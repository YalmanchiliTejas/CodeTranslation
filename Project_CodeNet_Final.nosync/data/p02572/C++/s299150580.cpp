#include<bits/stdc++.h>
#include<bits/stdc++.h>
#include <vector>
#define ll long long int
#define ve vector<ll>
#define vell vector<ll>
#define ve_pa vector<pair<ll,ll> >
#define pb push_back
#define mod 1000000007
#define ld long double 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define mll map<ll,ll>
#define mii map<int,int>
#define m_ve map<ll,vell >
#define min3(x,y,z) min(x,min(y,z))
#define max3(x,y,z) max(x,max(y,z))
#define se second
#define check cout<<"s"
#define checkx(x) cout<<x
#define W(x) while(x--)
#define ld long double
#define popcount(x) __builtin_popcountll(x)
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;
//int dx[]={1,-1,0,0},dy[]={0,0,1,-1};

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL); 
cout.tie(NULL);
int n;cin>>n;
ll a[n];
for(int i=0;i<n;i++)
cin>>a[i];
ll pre[n];
pre[n-1]=a[n-1];
for(int i=n-2;i>=0;i--)
pre[i]=(pre[i+1]+a[i])%mod;

ll ans=0;
for(int i=0;i<n-1;i++)
{
	ans=(ans+a[i]*pre[i+1])%mod;
}
cout<<ans;




}
 
 
