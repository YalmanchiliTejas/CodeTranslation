#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define rfor(i, a, b) for(int i = a; i < (int)b; i++)
#define all(ary) (ary).begin(), (ary).end()
#define debug(x) cerr << #x << ": " << x << '\n'
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
using namespace std;
using v = vector<int>;
using ll = long long;
template <class T = int> T in(){ T x; cin >> x; return (x);}
const int dy[4] = {-1, 0, 0, 1};
const int dx[4] = {0, -1, 1, 0};

int main(int argc, char *argv[]){
    int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
    int t1 = a * x + b * y;
    // int t2 = 2 * c * max(x, y);
    // int p = x < y ? a : b;
    // int t3 = 2 * c * max(x, y) + p * abs(x - y);
    // cout << min(t1, min(t2, t3)) << endl;
    int t2 = t1;
    for(int i = 1; i < max(x, y) + 1; i++){
        int t = 2 * c * i; // abをi個買う
        t2 = min(t2, max(0, (x - i)) * a + max(0, (y - i)) * b + t);
    }
    cout << min(t1, t2) << endl;
    return 0;
}