/*
 * Author: Anmol Choudhary
 */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define rep0(a,b) for(int a=0;a<b;a++)
#define rep1(a,b) for(int a=1;a<=b;a++)
#define repp(a,b,c) for(int a=b;a<c;a++)
#define in insert
#define len length()
#define si size()
#define lb lower_bound
#define ub upper_bound
#define beg begin()
#define en end()
#define f first
#define s second
#define pr(a) cout<<a
#define pr2(a,b) cout<<a<<" "<<b<<"\n"
#define nextl cout<<"\n"
#define deb(x) cout<<#x<<"="<<x<<"\n"
#define deb2(x,y) cout<<"["<<#x<<"="<<x<<"] , ["<<#y<<"="<<y<<"]"<<"\n"
const ll mod = 1000000007;
const ll maxn = 100005;
const ll mm = 1e+18;
ll power(ll x, ll y)
{
    ll res = 1;
    x = x % mod;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % mod;
        y = y>>1;
        x = (x*x) % mod;
    }
    return res;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    if(n==m) cout<<"Yes";
    else cout<<"No";
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
        //nextl;
    }
    return 0;
}
