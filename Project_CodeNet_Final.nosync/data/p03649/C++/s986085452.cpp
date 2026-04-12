#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,num,add,k;
int main(void){
	priority_queue<ll> pq;
	scanf("%lld",&n);
	for(int i=0;i<n;++i) scanf("%lld",&num), pq.push(num);
	while(pq.top()+add>=n){
		num = pq.top()+add;
		pq.pop();
		k = num/n;
		num-=k*n;
		add+=k;
		pq.push(num-add);
	}
	printf("%lld\n",add);
	return 0;
}