#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	deque<int> Q;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		int val;
		scanf("%d", &val);
		if(i & 1) Q.push_back(val);
		else Q.push_front(val);
	}
	if((n & 1)) reverse(Q.begin(), Q.end());
	for(auto v : Q) 
		printf("%d ", v);
	return 0;
}
		