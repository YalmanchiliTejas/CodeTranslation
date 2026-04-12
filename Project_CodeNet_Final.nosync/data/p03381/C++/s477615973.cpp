#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = int(2e5)+5;

int A[maxn], B[maxn];

int main(void)
{
	int n;
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
	{
		scanf("%d", &A[i]);
		B[i] = A[i];
	}
	sort(B, B+n);

	int cent = n/2-1;
	for(int i = 0;i < n;i++)
	{
		if(A[i] <= B[cent]) printf("%d ", B[cent+1]);
		else printf("%d ", B[cent]);
	}
	printf("\n");
}