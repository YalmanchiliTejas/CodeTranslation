#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(0)
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
const int MOD=998244353;
const int N=(int)3*1e5+9;
const int inf = 1<<30;


template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
int est[N],west[N];
int n;
int32_t main() {
IOS;
int a,b,c,x,y,ans=0;

cin>>a>>b>>c>>x>>y;
while(x>0 || y>0){ 
    if(x>0 and y>0){ 
        ans+=min(a+b,2*c);

    }else if(x>0) ans+=min(a,2*c);
    else ans+=min(b,2*c);
    x--,y--;
}
    cout<<ans<<endl;
}