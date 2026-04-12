#include <bits/stdc++.h>
#define IOS   ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define mp    make_pair
#define pb    push_back
#define F     first
#define pi 	  3.14159265358979323846
#define S     second
#define ll    long long
#define ld    long double
#define sz(s) (ll)s.size()
#define vl    vector < ll >
#define pll   pair < ll, ll >
#define ml    map < ll, ll >
#define mod   1000000007
#define qe	  998244353
#define maxn  100005
#define mx    1005
#define rep(i,a,b)  for(i=a;i<b;i++)
#define inv(i,a,b)  for(i=a;i>=b;i--)
#define all(a)  (a).begin(),(a).end()
using namespace std;
int main(){
//	#ifndef ONLINE_JUDGE
//    if (fopen("input.txt", "r"))
//    {
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
//    }
//	#endif
	IOS;
	ll t,n,l;
	ll i,m,mn,q,j,x,y,ans=0,sum=0,k,c;
	string s,s1;
	cin>>n;
	ll a[n],b[n];
	rep(i,0,n)cin>>a[i];
	b[n-1]=a[n-1];
	inv(i,n-2,0)b[i]=(a[i]+b[i+1])%mod;
	rep(i,0,n-1){
		ans+=(a[i]*b[i+1])%mod;
		ans%=mod;
	}
	cout<<ans;
}