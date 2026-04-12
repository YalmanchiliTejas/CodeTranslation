#pragma GCC optimize("O3", "unroll-loops")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
#define ull unsigned long long
#define si short int
#define ll long long
#define piii pair<pair<int, int>, int>
#define piiii pair<pair<int, int>, pair<int, int>>

/*-----------------------------------------------------MATH------------------------------------------------*/
inline ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

inline int pwm(ll xx, ll pow, int MD) {
    if (pow < 0) { pow = pow % (MD - 1) + MD - 1; }
    ll mlt = 1;
    while (pow) {
        if (pow & 1) {
            mlt *= xx;
            mlt %= MD;
        }
        xx *= xx;
        pow >>= 1;
        xx %= MD;
    }
    return (int) mlt;
}

inline ll gcdex(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll xx, yy;
    ll gc = gcdex(b, a % b, yy, xx);
    x = xx;
    y = yy - (a / b) * xx;
    return gc;
}

inline int inv(ll r, int _mod) { return pwm(r % _mod, _mod - 2, _mod); }

inline int64_t hilbertOrder(int x, int y, int pow, int rotate) {
    if (pow == 0) {
        return 0;
    }
    int hpow = 1 << (pow - 1);
    int seg = (x < hpow) ? (
            (y < hpow) ? 0 : 3
    ) : (
                      (y < hpow) ? 1 : 2
              );
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquareSize = int64_t(1) << (2 * pow - 2);
    int64_t ans = seg * subSquareSize;
    int64_t add = hilbertOrder(nx, ny, pow - 1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}

/*-----------------------------------------------------MATH------------------------------------------------*/
ll mod = 1e9 + 7;
vector<int> arr;
void solve() {
   int a,b;
   cin>>a>>b;
   if(a==b) cout<<"Yes";
   else cout<<"No";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("C:\\Users\\Maximus\\CLionProjects\\Codeforces\\BestTeam\\output.txt", "r", stdin);
    //freopen("C:\\Users\\Maximus\\CLionProjects\\Codeforces\\BestTeam\\output.txt", "w", stdout);
    unsigned int beg_time = clock();

    int n = 1;
    for (int i = 0; i < n; i++) solve();


    unsigned int end_time = clock();
    //cout<<endl<<endl<<end_time-beg_time;

    return 0;
}