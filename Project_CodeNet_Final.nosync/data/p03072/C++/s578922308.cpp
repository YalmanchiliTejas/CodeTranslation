#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

static void B_GreatOceanView();

int main()
{

	B_GreatOceanView();

	fflush(stdout);
	return 0;
}

static void B_GreatOceanView()
{
	int N = 0;
	int H[100] = { 0 };

	scanf(" %d", &N);

	for (int i = 0; i < N; i++) {
		scanf(" %d", &H[i]);
	}

	int viewable = 1;
	int maxHeight = H[0];
	for (int i = 1; i < N; i++) {
		if (H[i] >= maxHeight) {
			viewable++;
			maxHeight = H[i];
		}
	}

	printf("%d\n", viewable);
}
