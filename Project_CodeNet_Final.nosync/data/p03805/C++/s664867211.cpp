#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <list>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <iterator> 
#include <limits>

#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define ALL(a) (a).begin(),(a).end()
#define RALL(A) (a).rbegin(),(a).rend()
#define PB push_back
#define MP make_pair

#define dump(x) cerr << #x << " = " << (x) << endl;

using namespace std;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = numeric_limits<int>::max() / 2;
const int NEG_INF = numeric_limits<int>::min() / 2;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

int N, M;
const int MAX_N = 8;
VI tree[MAX_N + 1];

bool visit[MAX_N + 1];

int ans = 0;
void dfs(int u) {
    visit[u] = true;
    for (auto v : tree[u]) {
        if (!visit[v]) {
            dfs(v);
        }
    }
    ans += 1;
    for (int i = 1; i <= N; i++) {
        if (!visit[i]) {
            ans -= 1;
            break;
        }
    }
    visit[u] = false;
}

int main(int argc, char const* argv[])
{
    cin >> N >> M;
    REP(i, M) {
        int a, b;
        cin >> a >> b;
        tree[a].PB(b);
        tree[b].PB(a);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}

