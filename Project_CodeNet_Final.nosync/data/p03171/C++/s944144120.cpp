#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << ", "
template <typename T> ostream& operator<<(ostream& _o_, const vector<T>& _v_){ \
 if(!_v_.empty()){_o_<<'[';copy(_v_.begin(),_v_.end(),ostream_iterator<T>(_o_,", "));_o_<<"\b\b]";}return _o_;}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
typedef unsigned int uint;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef unsigned char uchar;
struct secure_hash {
 static uint64_t splitmix64(uint64_t x) {
  x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); }
 size_t operator()(uint64_t x) const {
  static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); } };
template<typename T> using V = vector<T>;
template<typename T, typename U> using umap = unordered_map<T,U,secure_hash>;
template<typename T> using uset = unordered_set<T,secure_hash>;
template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using max_heap = priority_queue<T>;

int n;
V<int> a;
V<V<ll>> dp;

ll f(int i, int j)
{
    if (i > j or i < 0 or j >= n) return 0;
    ll& ans = dp[i][j];
    if (ans == -1) {
        bool turn = (j-i+1) % 2 == n % 2;
        if (turn) {
            ans = max(f(i+1, j) + a[i], f(i, j-1) + a[j]);
        }
        else {
            ans = min(f(i+1, j) - a[i], f(i, j-1) - a[j]);
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    rep(i,0,n) cin >> a[i];
    dp.resize(n, V<ll>(n, -1));
    cout << max(f(1,n-1)+a[0], f(0,n-2)+a[n-1]) << endl;
}
