// 基本テンプレート
 
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
using namespace std;
 
#define rep(i,a,n) for(int (i)=(a); (i)<(n); (i)++)
#define repq(i,a,n) for(int (i)=(a); (i)<=(n); (i)++)
#define repr(i,a,n) for(int (i)=(a); (i)>=(n); (i)--)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define int long long int
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
typedef pair<int, int> pii;
typedef long long ll;
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const ll INF = 4e18;
const ll MOD = 1000000007LL;

int N;
 
signed main() {
    cin >> N;
    vector<pii> P;

    int mi = INF, ma = 0;
    rep(i,0,N) {
        int X, Y;
        cin >> X >> Y;
        if(X > Y) swap(X, Y);
        chmin(mi, X);
        chmax(ma, Y);
        P.push_back(make_pair(X, Y));
    }
    sort(P.begin(), P.end());

    int ans = INF;
    int R_ma = P[N-1].first, B_mi = INF;
    rep(i,0,N) chmin(B_mi, P[i].second);
    chmin(ans, (ma-B_mi) * (R_ma-mi));

    set<pii> S;
    S.insert(make_pair(P[0].second, INF));
    rep(i,1,N) S.insert(make_pair(P[i].second, i));

    while(1) {
        // printf("A = %lld, B = %lld\n", S.rbegin()->first, S.begin()->first);
        int diff = S.rbegin()->first - S.begin()->first;
        // printf("ma = %lld, mi = %lld, diff = %lld\n", ma, mi, diff);
        chmin(ans, (ma-mi)*diff);
        if(S.rbegin()->second == INF) break;
        pii nxt = make_pair(P[S.rbegin()->second].first, INF);
        S.erase(*S.rbegin());
        S.insert(nxt);
    }
    cout << ans << endl;
    return 0;
}