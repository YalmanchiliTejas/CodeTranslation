#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
int main()
{
    int r, g, b;
    cin >> r >> g >> b;
    r = r * 100 + g * 10 + b;
    if (r % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}