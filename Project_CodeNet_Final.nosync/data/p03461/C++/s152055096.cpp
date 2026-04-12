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
const ll INF = 1001001001001001LL;
const ll MOD = 1000000007LL;

int A, B;
int D[15][15], C[110][110];
const int N = 100;
const int V = (N+1)*2;
const int E = (N+1)*(N+1) + 2*N;
const int S = V-1, T = V;
 
signed main() {
    cin >> A >> B;
    repq(i,1,A) repq(j,1,B) cin >> D[i][j];

    repq(a,0,N) repq(b,0,N) {
        repq(x,1,A) repq(y,1,B) chmax(C[a][b], D[x][y] - a*x - b*y);
    }

    repq(x,1,A) repq(y,1,B) {
        int cost = INF;
        repq(a,0,N) repq(b,0,N) chmin(cost, a*x + b*y + C[a][b]);
        if(cost != D[x][y]) {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    cout << "Possible" << endl;
    printf("%lld %lld\n", V, E);
    printf("%lld %lld X\n", S, 1LL);
    printf("%lld %lld Y\n", S-1, T);
    rep(i,1,N) printf("%lld %lld X\n", i, i+1);
    rep(i,1,N) printf("%lld %lld Y\n", N+i, N+i+1);

    repq(a,0,N) repq(b,0,N) {
        int u = (a ? a   : S);
        int v = (b ? S-b : T);
        printf("%lld %lld %lld\n", u, v, C[a][b]);
    }
    printf("%lld %lld\n", S, T);
    return 0;
}