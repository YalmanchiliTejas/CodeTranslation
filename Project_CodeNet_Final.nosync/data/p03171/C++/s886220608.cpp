#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
#include <list>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<long double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }
#define INF 1LL<<60

int main() {
    int N;
    cin >> N;
    vector<ll> a(N);
    for(int i=0; i<N; i++) {
        cin >> a[i];
    }

    // dp[i][j] : [i, j]が残ってる時の　次の手番 - そうじゃない方　の値
    vector<vector<ll>> dp(N, vector<ll>(N));
    for(int i=N-1; i>=0; --i)
        for(int j=i; j<N; ++j) {
            if(i == j)
                dp[i][j] = a[i];
            else
                dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
        }

    cout << dp[0][N-1] << endl;
    return 0;
}