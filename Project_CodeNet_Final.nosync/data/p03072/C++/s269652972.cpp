#include<bits/stdc++.h>
#define ll  long long
#define speed_up    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define pb push_back
#define Max(x,y,z) max(x,max(y,z))
#define f first
#define s second
#define lbd lower_bound
#define sz(x)       (ll)x.size()
#define pi 3.1415926536
#define mod 1000000007
using namespace std;
void solve()
{
    ll n,m,k,x,y=0,res=0,l,cnt=0,sum=0,z,sum1=0,cnt1=0,h,res1;
    cin>>n;
    rep(i,0,n)
    {
        cin>>x;
        if(x>=res)
            cnt++;
        res=max(res,x);
    }
    cout<<cnt;



}
int main()
{   speed_up
    ll t;
   // cin>>t;
    t=1;
    while(t--)
        solve();
}
