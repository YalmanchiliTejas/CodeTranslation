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
    ll n,m,k,x,y,res=0,l,a=0,b=0,c=0,d=0,cnt=0,sum=0,z;
    string s;
    cin>>n;
    cin>>s;
    cin>>k;
    rep(i,0,n)
        if(s[i]!=s[k-1])
            s[i]='*';
    cout<<s;


}
int main()
{
    ll t;
    //cin>>t;
    t=1;
    while(t--)
        solve();
}
