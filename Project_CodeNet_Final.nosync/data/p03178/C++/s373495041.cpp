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

const ll M = 1e9+7;

void add(ll& x, ll y)
{
    x += y;
    x %= M;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string K;
    ll n, d;
    cin >> K >> d;
    n = K.size();
    V<int> k(n);
    rep(i,0,n) k[i] = K[i] - '0';
    // dp[x][y] - number of numbers with sum of i digits equal to x mod d (base 10)
    //               (y = 1 already small) (y = 0 not small by the moment)
    V<V<ll>> dp(d, V<ll>(2));
    rep(digit,0,k[0]+1) {
        ll a = digit % d;
        if (digit < k[0]) 
            ++dp[a][1];
        else // digit == k[0]
            ++dp[a][0];
    }
    rep(i,1,n) {
        V<V<ll>> ndp(d, V<ll>(2));
        rep(value,0,d) {
            rep(digit,0,10) {
                rep(already_small,0,2) {
                    if (not already_small and digit > k[i]) continue;
                    add(ndp[(value+digit)%d][already_small|(digit<k[i])], dp[value][already_small]);
                }
            }
        }
        dp = ndp;
    }
    cout << ((dp[0][0] + dp[0][1] - 1) % M + M) % M << endl;
}
