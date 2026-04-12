#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;
typedef vector<ll> vll;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
const double pi=acos(-1);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    vll a(n);
    rep(i,n)
		cin>>a[i];
    ll sum=0;
    for(int i=0;i<n;i++)
        sum+=a[i];
    ll ans=0;
    rep(i,n)
	{
        sum-=a[i];
        sum%=1000000007;
        ans+=sum*a[i];
        sum+=1000000007;
        ans%=1000000007;
    }
    cout<<ans<<endl;
}