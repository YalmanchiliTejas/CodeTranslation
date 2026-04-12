#include <bits/stdc++.h>
using namespace std;
// define
// #define int long long
#define UNIQUE(v) v.erase(unique(all(v)), v.end());
#define ZIP(v) sort(all(v)),UNIQUE(v)
#define ADD(a, b) a = (a + b) % mod
#define SUB(a, b) a = (a+mod-b)%mod
#define MUL(a, b) a = (((a)%mod) * ((b)%mod)) % mod
#define rollcall cout << "I'm Sucu." << endl;
#define repi(i,m,n) for(int i = m;i < n;i++)
#define drep(i,n,m) for(int i = n;i >= m;i--)
#define rep(i,n) repi(i,0,n)
#define rrep(i,n) repi(i,1,n+1)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend()
#define dmp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define fi first
#define se second
// typedef
typedef complex<double> Point;
typedef pair<int, int> P;
typedef pair<int, P> PP;
typedef pair<P, int> Pi;
typedef vector<int> vi;
typedef deque<int> dq;
const int inf = 1e9+7;
// const int INF = 1e18+7;
const int mod = 1e9+7;
// int sum = accumulate(a, a+n, 0LL);
// int mx = max_element(a, a+n);
// int mn = min_element(a, a+n);
// int cnt = count(a, a+n, k);

int A,B,C,X,Y;

signed main()
{
    cin >> A >> B >> C >> X >> Y;

    int ans=inf;

    for(int i=0;i<=100000;i++)
    {
        ans=min(ans,i*2*C+max(0,X-i)*A+max(0,Y-i)*B);
    }

    cout << ans << endl;
    
    
    return 0;
}