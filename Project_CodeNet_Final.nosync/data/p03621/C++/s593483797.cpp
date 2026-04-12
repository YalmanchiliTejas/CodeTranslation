#include <cassert>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 998244353
#define rep(i,x) for(int i=0;i<x;i++)
string s,t;
int A,B;
ll modpow(ll x,ll n)
{
	ll res=1;
	while(n>0)
	{
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
ll F[50005],R[50005];
void make(){
	F[0] = 1;
	for(int i=1;i<50005;i++) F[i] = F[i-1]*i%mod;
	for(int i=0;i<50005;i++) R[i] = modpow(F[i],mod-2);
}
ll C(int a,int b){return F[a]*R[b]%mod*R[a-b]%mod;}
int main(){
	cin>>s>>t;make();
	rep(i,s.size()){
		if(s[i]==t[i]&&s[i]=='1') A++;
		else if(s[i]=='1') B++;
	}
	ll ans = 0;
	for(int i=0;i<=A;i++){
		ll ret = F[i]*F[A-i]%mod*F[A-i]%mod;
		ll add = 0;
		int sum = i+B;
		for(int i=0;i<=B;i++){
			ll x = C(B,i);
			x = x*modpow(B-i,sum)%mod;
			if(i%2==0) add=(add+x)%mod;
			else add=(add+mod-x)%mod;
		}
		ans += ret*add%mod*F[B]%mod*C(A+B,i+B)%mod*C(A,i)%mod;
	}
	cout<<ans%mod<<endl;
}