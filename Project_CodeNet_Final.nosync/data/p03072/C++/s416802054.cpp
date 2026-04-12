#include <bits/stdc++.h>
using namespace std;
int main(){
	int N;
	scanf("%d",&N);
	int* mon = new int[N];
	int* hest = new int[N];
	int maxH = 0;
	for (int i = 0; i < N; ++i)
	{
		scanf("%d",&mon[i]);
		maxH = max(maxH, mon[i]);
		hest[i] = maxH;
	}
	int count = 0;
	for (int i = 0; i < N; ++i)
	{
		if (mon[i] >= hest[i])
			count ++;
	}
	printf("%d\n", count);
}