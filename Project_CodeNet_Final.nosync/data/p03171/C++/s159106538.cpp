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

#define debug(x) cout << #x << " = " << x << endl;
#define trace1(x)                cout<<#x<<": "<<x<<endl
#define trace2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cout<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl


typedef long long int ll;
typedef long double ld;
typedef vector<int> vi;
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

const ll mod = 1000000007;
const ll inf = (ll) 1e15;

ll power(ll a, ll b, ll m = mod) {if (b == 0) return 1; if (b == 1) return (a % m); ll x = power(a, b / 2, m); x = (x * x) % m; if (b % 2) x = (x * a) % m;return x;}
ll max(ll a, ll b) { return (a > b ? a : b); }
ll min(ll a, ll b) { return (a < b ? a : b); }

const int N=3005,M=1e5+5;

ll dp1[N][N],dp2[N][N];
bool memo1[N][N],memo2[N][N];
ll psum[N];
ll a[N];
int n;

ll func1(int,int,int);
ll func2(int,int);

ll func1(int i,int j)
{
    if(i>j||i>n||j<1)
        return 0;
    if(i==j)
        return a[i];
    if(memo1[i][j])
        return dp1[i][j];
    memo1[i][j]=true;
    ll ret=0;
    ret=max(ret,a[i]+(psum[j]-psum[i]-func1(i+1,j)));
    ret=max(ret,a[j]+(psum[j-1]-psum[i-1]-func1(i,j-1)));
    return dp1[i][j]=ret;
}

/*ll func2(int i,int j)
{
    if(i>j || i>n || j<1)
        return 0;
    if(i==j)
        return a[i];
    if(memo2[i][j])
        return dp2[i][j];
    memo2[i][j]=true;
    ll ret=0;
    ret=max(ret,a)
}*/

void solve() {

    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        psum[i]=psum[i-1]+a[i];
    }
    ll X=func1(1,n);
    ll Y=psum[n]-X;
    cout << X-Y << endl;
}

int main() {
    IOS;
    int t = 1, num = 1;   ///// change this t for number of testcase globally
    while (t--) {
        solve();
    }
    return 0;
}
