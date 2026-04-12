#pragma region include
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <cstdio>
#include <tuple>
#define ALL(obj) (obj).begin(),(obj).end()
#define RALL(obj) (obj).rbegin(),(obj).rend()
#define REP(i, n) for(int i = 0; i < (n); i++)
#define REPR(i, n) for(int i = (n); i >= 0; i--)
#define FOR(i,n,m) for(int i = (n); i < (m); i++)
#define MOD 1000000007
#define INF 1000000000
#define LLINF 4000000000000000000
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#pragma endregion

vector<vector<ll>> dp;
vector<vector<bool>> visited;
VI a;
int N;

ll point(int l, int r) {
    if (visited[l][r]) return dp[l][r];
    if (l == r) dp[l][r] = a[l];
    else dp[l][r] = max(a[r] - point(l, r - 1), a[l] - point(l + 1, r));
    visited[l][r] = true;
    return dp[l][r];
}

int main() {
    cin >> N;
    dp.assign(N, vector<ll>(N));
    visited.assign(N, vector<bool>(N, false));
    a.resize(N);
    REP(i, N) {
        cin >> a[i];
    }
    cout << point(0,N-1) << endl;
    getchar(); getchar();
}