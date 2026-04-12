#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"
#define int long long
typedef vector<int> vi;
#define all(x) x.begin(),x.end()
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define OO 1e9
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
typedef long long ll;
#define in_range(x, y, r, c) ((x >= 0 && x < r && y >= 0 && y < c))

const double eps=1e-9;
const  int MOD=1e10;
const int N=1e5+9;
const int inf = 1<<30;


template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }


int32_t main() {
    IOS;
int n;
cin>>n;
int ans=1,mx;
cin>>mx;
    for (int i = 1; i <n     ; ++i) {
        int a;
        cin>>a;
        if(a>=mx)mx=max(a,mx),ans++;
    }
    cout<<ans;
}