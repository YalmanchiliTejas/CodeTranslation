// 11:50
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <tuple>
using namespace std;
typedef long long ll;
#define for1(i,n) for (ll i=0;i<(n);(i)++)
#define for2(i,m,n) for (ll (i)=(m);(i)<(n);(i)++)
#define for3(i,m,n,d) for (ll (i)=(m);(i)<(n);(i)+=(d))
#define INF (1LL << 60)
#define STRING(str) #str
#define DEBUG 1
#if DEBUG
    #define dump(var) dump2(STRING(var), var)
#else
    #define dump(var)
#endif

template <typename T>
void dump2(const string& name, const T& value)
{
    cerr << name << ": " << value << endl;
}
void dump2(const string& name, const tuple<ll,ll,ll>& value)
{
    ll a,b,c;
    tie(a,b,c) = value;
    cerr << name << ": (" << a << ", " << b << ", " << c << ")" << endl;
}

string A[10];
ll H,W;

bool dfs(ll h, ll w)
{
    bool ret = false;
    if (A[h][w] != '#') {
        return false;
    }
    if (h == H-1 && w == W-1) {
        return true;
    }
    if (h < H-1) {
        ret = ret || dfs(h+1, w);
    }
    if (w < W-1) {
        ret = ret || dfs(h, w+1);
    }
    return ret;
}

void solve()
{
    cin >> H >> W;
    ll cnt = 0;
    for1(h,H) {
        string s;
        cin >> s;
        A[h] = s;
        for (char a : s) {
            if (a == '#') {
                ++cnt;
            }
        }
    }
    dump(cnt);
    if (cnt != H + W - 1) {
        cout << "Impossible" << endl;
        return;
    }
    bool result = dfs(0,0);
    if (result) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
