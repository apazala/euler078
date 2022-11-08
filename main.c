#include <stdio.h>

#define MOD 1000000
#define MAXVAL 60001

int pent[400];
int npent;

int partitions[MAXVAL];

void init() {
	int p = 0;
	int k = 1;
	while (p < MAXVAL) {
		p = 3 * k*k;
		pent[npent++] = (p - k) / 2;
		p = (p + k) / 2;
		pent[npent++] = p;
		k++;
	}	
}

int main()
{
	init();

	partitions[0] = 1;
	for (int i = 1; i < MAXVAL; i++) {
		int index;
		int j = 0;
		int part = 0;
		int sign = 0;
		for (;;) {
			index = i - pent[j];
			j++;
			if (index < 0)break;
			part += (sign) ? -partitions[index] : partitions[index];
			if (sign) {
				while (part < 0)part += MOD;
			}
			else {
				while (part >= MOD)part -= MOD;
			}
			index = i - pent[j];
			j++;
			if (index < 0)break;
			part += (sign) ? -partitions[index] : partitions[index];
			if (sign) {
				while (part < 0)part += MOD;
			}
			else {
				while (part >= MOD)part -= MOD;
			}

			sign = !sign;
		}
		partitions[i] = part;
		if (!part) {
			printf("%d\n", i);
			break;
		}
	}

	return 0;
}
