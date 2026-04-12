#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
#include <iomanip>

using namespace std;
using ll = int64_t;
using VL = vector<ll>;
using VD = vector<double>;
using VVL = vector<VL>;
using VVD = vector<VD>;

#define FOR(i, start, end) for(ll i = (start), (i ## xxxx_end)=(end); i < (i ## xxxx_end); ++i)
#define FORD(i, start, end) for(ll i = (start), (i ## xxxx_end)=(end); i > (i ## xxxx_end); --i)
#define REP(i, n) FOR(i, 0, n)
#define REPD(i, n) FORD(i, n - 1, -1)

#define ALL(x) (x).begin(), (x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

template<class T, class U>bool chmax(T &a, const U &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T, class U>bool chmin(T &a, const U &b) { if (b<a) { a=b; return 1; } return 0; }

template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj) {o << "{"; for (auto &x : obj) o << " {" << x.first << " : " << x.second << "}" << ","; o << " }"; return o;}
template <class T>ostream &operator<<(ostream &o, const set<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const multiset<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const vector<T>&obj) {o << "{"; for (int i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? ", " : "") << obj[i]; o << "}"; return o;}
template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&obj) {o << "{" << obj.first << ", " << obj.second << "}"; return o;}
template <template <class tmp>  class T, class U> ostream &operator<<(ostream &o, const T<U> &obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr)o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
void print(void) {cout << endl;}
template <class Head> void print(Head&& head) {cout << head;print();}
template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) {cout << head << " ";print(forward<Tail>(tail)...);}

#define INF 1000000000000
#define MOD 1000000007

ll N, TARO;
VL A;
VVL dp;

ll f(ll i, ll j) {
    if(dp[i][j] != -1)
        return dp[i][j];
    
    if(i == j)
        return dp[i][j] = 0;
    
    if((j - i) % 2 == TARO) {
        return dp[i][j] = max(f(i + 1, j) + A[i], f(i, j - 1) + A[j - 1]);
    }
    else {
        return dp[i][j] = min(f(i + 1, j) - A[i], f(i, j - 1) - A[j - 1]);
    }
}

void solve() {
    cin >> N;
    TARO = N % 2;
    A = VL(N);
    for(auto& a : A) cin >> a;
    dp = VVL(N + 1, VL(N + 1, -1));
    print(f(0, N));
}

int main() {
    solve();
    return 0;
}