#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string> //C++
#include <iostream> //C++
#include <vector> //C++
#include <algorithm> //C++



using namespace std; //C++






int main()
{
	int i, N;

	char a[5];

	scanf("%s", &a);

	for (i = 0; i < 4; i++) {
		if (a[i] == 'A' && a[i + 1] == 'C') {
			printf("Yes");
			return 0;
		}
	}

	cout << "No";





}

