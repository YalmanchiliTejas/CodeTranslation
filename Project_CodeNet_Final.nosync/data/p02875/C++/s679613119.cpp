#include <bits/stdc++.h>
using namespace std;
mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());
const int N = 1e7 + 1,M = 998244353;
int fact[N] = {1},inv[N];
int power(int base,int to){
	int ret = 1;
	while(to){
		if(to&1)ret = ret*1LL*base%M;
		to>>=1;
		base = base*1LL*base%M;
	}
	return ret;
}
void add(int &a,int b){
	a+=b;
	if(a >= M)a-=M;
	if(a < 0)a+=M;
}
int choose(int n,int k){return (fact[n]*1LL*inv[k]%M)*inv[n - k]%M;}
int main(){
	//freopen("input.txt","r",stdin);
	int n;
	cin >> n;
	for(int i = 1;i < N;i++)fact[i] = fact[i - 1]*1LL*i%M;
	inv[N - 1] = power(fact[N - 1],M - 2);
	for(int i = N - 1;i;i--)inv[i - 1] = inv[i]*1LL*i%M;
	int ans = power(3,n);
	for(int i = n/2 + 1;i <= n;i++)
		add(ans,-choose(n,i)*2LL*power(2,n - i)%M);
	printf("%d\n",ans);
}