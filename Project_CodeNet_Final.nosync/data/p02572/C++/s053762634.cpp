#include<bits/stdc++.h>
#pragma GCC optimize(2)
#define ll long long
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,n,a) for(int i=n;i>=a;i--)
#define endl '\n'
#define eps 0.000000001
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int INF=0x3f3f3f3f;
const ll inf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
const int maxn=2e5+5;
int n;ll a[maxn],pre[maxn];
int main(){
	int n;cin>>n;
	pre[0]=pre[1]=0;
	rep(i,1,n) cin>>a[i],pre[i+1]=(pre[i]+a[i])%mod;
	ll sum=0;
	rep(i,1,n){
		ll cur=(pre[i]*a[i])%mod;
		sum=(sum+cur)%mod;
	}
	cout<<sum<<endl;
}
