#include<bits/stdc++.h>
using namespace std;
 
template <class T1, class T2>
ostream& operator << (ostream& out, const pair <T1, T2> p)
{
    out << '(' << p.first << ',' << p.second << ')';
        return out;
}
 
template <class T1, class T2>
istream& operator >> (istream& in, pair<T1, T2> &p)
{
    in >> p.first >> p.second;
        return in;
}
 
template <class T>
istream& operator >> (istream& in, vector<T> &v)
{
    for (T &x : v)
        in >> x;
    return in;
}
 
template <class T>
ostream& operator << (ostream& out, const vector<vector<T> > &v)
{
    for (const vector<T> &x : v)
        out << x << '\n';
    return out;
}
 
template <class T>
ostream& operator << (ostream& out, const vector<T> &v)
{
    for (const T &x : v)
        out << x << ' ';
    return out;
}
 
template <class T>
ostream& operator << (ostream& out,const set<T> &s)
{
    for (const T &x : s)
        out << x << ' ';
    return out;
}
 
 
#define ll long long
#define lf long double
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef pair <ll,ll > ii;
typedef vector <ll> vi;
typedef vector <ii> vii;
typedef vector <bool> vb;
typedef vector <vector <ll> > vv;
typedef vector <vector <vector<ll> > > vvv;
typedef vector <string> vs;
typedef vector <lf> vf;
#define sz(x) (ll)(x).size()
#define tr1(x) cerr << #x << ": " << x << nl
#define tr2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << nl
#define tr3(x,y,z) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<nl
#define tr4(x,y,z,w) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<" | "<<#w<<": "<<w<<nl
#define epsilon 0.00000001L
#define inf 9999999999999999ll// ~ 10^16
#define nl "\n"
#define all(x) x.begin(), x.end()
#define r_all(x) x.rbegin(), x.rend()
#define fast()  ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod 1000000007ll
#define modulo 998244353ll
ll power(ll a,ll b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}

int main()
{
    fast();
    ll n,x,m;
    cin>>n>>x>>m;

    vi ind(m,-1);

    vi a;
    a.pb(x);
    ind[x]=0;
    ll index=1;
    x=(x*x)%m;
    while(ind[x]==-1 && sz(a)<n)
    {
        ind[x]=index;
        a.pb(x);
        x=(x*x)%m;
        index++;
    }
    index=ind[x];
    if(sz(a)==n)
    {
        ll sum=0;
        for(ll i=0;i<n;i++)
            sum+=a[i];
        cout<<sum<<nl;
    }
    else
    {
        n-=index;
        ll cycle=sz(a)-index;
        ll num=n/cycle;
        ll rem=n%cycle;
        ll prev=0;
        for(ll i=0;i<index;i++)
            prev+=a[i];
        ll rep=0;
        for(ll i=index;i<sz(a);i++)
            rep+=a[i];
        if(a.back()!=0)
        {
            rep*=num;
            for(ll i=index;i<index+rem;i++)
                rep+=a[i];
        }
        cout<<prev+rep<<nl;
    }
    
}
