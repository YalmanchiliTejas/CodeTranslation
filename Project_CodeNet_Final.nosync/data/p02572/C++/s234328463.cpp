#include <iostream> 
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
#include<set>
#include<queue>
#include<deque>
#include<sstream>
#include<cmath>
#include<bitset>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define req(i,n) for(int i = 1;i <=  n; i++)
#define rrep(i,n) for(int i = n-1;i >= 0;i--)
#define ALL(obj) begin(obj), end(obj)
#define RALL(a) rbegin(a),rend(a)
typedef long long int ll;
typedef long double ld;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T& val) {
    std::fill((T*)array, (T*)(array + N), val);
}
const int MAX = 510000;
const int MOD = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll n, q, cnt = 0,h,w, ans = 0,a,b; string s;
int dx[9] = { -2,-2,-2,-1,-1,-1,0,0,0 }, dy[9] = { 0,-1,-2,0,-1,-2,0,-1,-2 };
int main(void) {
    int n; cin >> n; vector<ll> a(n);
    ll sum = 0,ans = 0;
    rep(i, n) {
        cin >> a[i]; sum += a[i];
        sum %= MOD;
    }
    rep(i, n) {
        ans += (a[i] * (((sum - a[i])+MOD) % MOD))%MOD;
        ans %= MOD;
    }if (ans % 2==1) ans += MOD;
    cout << (ans / 2)%MOD << endl;
}