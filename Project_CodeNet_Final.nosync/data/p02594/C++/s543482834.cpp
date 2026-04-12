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
#define trv(a) cerr<<#a<<": ";for(ll zz=0;zz<sz(a);zz++) cerr<<a[zz]<<" ";cerr<<nl
#define trset(s) cerr<<#s<<": ";for(auto &i:s) cerr<<i<<" ";cerr<<nl
#define epsilon 0.000000001L
#define inf 9999999999999999ll// ~ 10^16
#define nl endl
#define all(x) x.begin(), x.end()
#define r_all(x) x.rbegin(), x.rend()
#define fast()  ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod 1000000007ll
#define modulo 998244353ll
ll power(ll a,ll b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}


int main()
{
    fast();
    ll x;
    cin>>x;
    if(x>=30)
        cout<<"Yes\n";
    else
        cout<<"No\n";
}
