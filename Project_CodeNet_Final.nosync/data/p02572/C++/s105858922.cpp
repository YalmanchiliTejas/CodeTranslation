#pragma GCC optimize(2)
#include<bits/stdc++.h> 
using namespace std;
#define ll long long
#define endl "\n"
const int MAX=1e6+7;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
ll a[MAX],b[MAX],c[MAX];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
	ll n,ans=0;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	//sort(a+1,a+n+1);
	b[n]=a[n];
	for(int i=n-1;i>=1;i--)b[i]=(b[i+1]+a[i])%mod;
	for(int i=1;i<=n;i++)c[i]=(c[i-1]+a[i]*(b[i+1]))%mod;
	cout<<c[n];
   return 0;
}  