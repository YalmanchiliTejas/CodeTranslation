#include<bits/stdc++.h>
using namespace std;

template<typename F, typename S>
ostream &operator<<(ostream &os, const pair<F, S> &p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "{";
    typename vector<T>::const_iterator it;
    for (it = v.begin(); it != v.end(); it++) {
        if (it != v.begin()) os << ", ";
        os << *it;
    }
    return os << "}";
}

template<typename T>
ostream &operator<<(ostream &os, const set<T> &v) {
    os << "[";
    typename set<T>::const_iterator it;
    for (it = v.begin(); it != v.end(); it++) {
        if (it != v.begin()) os << ", ";
        os << *it;
    }
    return os << "]";
}

template<typename F, typename S>
ostream &operator<<(ostream &os, const map<F, S> &v) {
    os << "[";
    typename map<F, S>::const_iterator it;
    for (it = v.begin(); it != v.end(); it++) {
        if (it != v.begin()) os << ", ";
        os << it->first << " = " << it->second;
    }
    return os << "]";
}

#define debug(x) cerr << #x << " = " << x << endl;
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl


typedef long long int ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long int> vll;
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
typedef map<int, int> mii;
typedef vector< pair<int, int> > vpii;

#define endl "\n";
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define tr(cont, it) for(decltype((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c),x) != (c).end())
#define F first
#define S second


const ld PI=acos(-1.0);
const ll mod = 1000000007;
const ll inf = (ll) 1e15;

ll power(ll a, ll b, ll m = mod) {if (b == 0) return 1; if (b == 1) return (a % m); ll x = power(a, b / 2, m); x = (x * x) % m; if (b % 2) x = (x * a) % m;return x;}
ll max(ll a, ll b) { return (a > b ? a : b); }
ll min(ll a, ll b) { return (a < b ? a : b); }

const int N=1e4+5;
const int M=1e5+5;

string s;
int d;
ll dp[N][3][111];

ll func(int idx,bool less,int m)
{
    if(idx==s.size())
    {
        return m==0;
    }
    if(dp[idx][less][m]!=-1)
        return dp[idx][less][m];
    ll ret=0;
    for(int i=0;i<10;i++)
    {
        if(less)
        {
            ret+=func(idx+1,1,(m+i)%d);
        }
        else
        {
            if(i>s[idx]-'0')
                break;
            if(i==s[idx]-'0')
                ret+=func(idx+1,0,(m+i)%d);
            if(i<s[idx]-'0')
                ret+=func(idx+1,1,(m+i)%d);
        }
        ret%=mod;
    }
    return dp[idx][less][m]=ret%mod;
}

void solve() {

    cin >> s >> d;
    memset(dp,-1, sizeof(dp));
    ll ans1=func(0,0,0);
    cout << (ans1-1+mod)%mod << endl;
}

int main() {
    IOS;
    int t = 1, num = 1;   ///// change this t for number of testcase globally
    while (t--) {
        solve();
    }
    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/