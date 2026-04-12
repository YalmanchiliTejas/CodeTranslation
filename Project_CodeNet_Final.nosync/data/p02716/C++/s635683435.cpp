#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define lf long double
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef pair <ll,ll> ii;
typedef vector <ll> vi;
typedef vector <ii> vii;
typedef vector <bool> vb;
typedef vector <vector <ll> > vv;
typedef vector <vector <vector<ll> > > vvv;
typedef vector <string> vs;
typedef vector <lf> vf;
#define tr1(x) cerr << #x << ": " << x << endl
#define tr2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl
#define tr3(x,y,z) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define tr4(x,y,z,w) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<" | "<<#w<<": "<<w<<endl
#define trv(a) cerr<<#a<<": ";for(ll zz=0;zz<a.size();zz++) cerr<<a[zz]<<" ";cerr<<endl
#define trii(x) cerr<<#x<<": ("<<x.F<<","<<x.S<<")\n";
#define trset(s) cerr<<#s<<": ";for(auto &i:s) cerr<<i<<" ";cerr<<"\n"
#define mod 1000000007ll
#define inf 9999999999999999ll
#define nl endl
#define sz(x) (ll)(x).size()
#define all(x) x.begin(), x.end()
#define modulo 998244353ll

ll fun(vi &a,ll index,ll req,map <ii,__int128> &m)
{
    if(req<0)
        return -inf;
    if(m.find(mp(index,req))!=m.end())
        return m[mp(index,req)];
    __int128 &an=m[mp(index,req)];
    ll n=sz(a);
    if(index>=n)
    {
        if(req!=0)
            return an=-inf;
        return an=0;
    }
    ll left=n-index;
    if(req>(left+1)/2)
    {
        return an=-inf;
    }
    return an=max(fun(a,index+1,req,m),a[index]+fun(a,index+2,req-1,m));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vi a(n,0);
    for(ll i=0;i<n;i++)
        cin>>a[i];
        map <ii,__int128> m;
        cout<<fun(a,0,sz(a)/2,m)<<nl;
}
