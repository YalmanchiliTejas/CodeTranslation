#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void)
{
	int n, a;
	scanf("%d", &n);
	deque<int> Q;
	int type = 0;
	for(int i = 0;i < n;i++)
	{
		scanf("%d", &a);
		if(type) Q.push_back(a);
		else Q.push_front(a);
		type = !type;
	}

	if(!type) reverse(Q.begin(), Q.end());
	for(auto it: Q) printf("%d ", it);
	printf("\n");
}