#include<bits/stdc++.h>
using namespace std;
#define LL long long 
LL read(){
	LL x = 0,f = 0;char ch = getchar();
	while(!isdigit(ch)) {if(ch=='-')f=1;ch=getchar();}
	while(isdigit(ch)) {x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
const int N = 2e5+100; 
const int mod = 1000000007;
LL n,pre[N],a[N];
int main()
{
	n = read();
	for(int i = 1;i <= n;i++){
		a[i] = read();
		pre[i] = pre[i-1]+a[i];
		pre[i] %= mod;
	}
	LL ans = 0;
	for(LL i = 1;i < n;i++){
		(ans+=(a[i]*(pre[n]-pre[i])%mod)%mod)%=mod;
	}
	cout << (ans%mod+mod)%mod << endl;
	return 0;
}