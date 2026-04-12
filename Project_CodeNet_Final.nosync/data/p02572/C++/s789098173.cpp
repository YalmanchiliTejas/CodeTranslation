#include<bits/stdc++.h>
#define M 1000000007
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	vector<int> v(n);
	for(int& x : v)
		scanf("%d",&x);
	long long ans = 0;
	vector<long long> sum(n);
	sum[n-1] = v[n-1];
	for(int i = n-2; i >= 0; i--)
		sum[i] = (sum[i+1] + v[i])%M;
	for(int i = 0; i < n-1; i++)
		ans = (ans + v[i]*sum[i+1])%M;
	printf("%lld\n", ans);
	return 0;
}