#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <iomanip>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define DEBUG

#ifdef DEBUG
#define var_dump(...) fprintf(stdout, __VA_ARGS__)
#define dump(a) cout << a << "\n";
#else
#define var_dump(...) 42
#define dump(a) 42
#endif

typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

int dy4[]={0, 0, 1, -1};
int dx4[]={1, -1, 0, 0};
int dx8[]={0, 0, 1, -1, 1, 1, -1, -1};
int dy8[]={1, -1, 0, 0, 1, -1, -1, 1};

// https://beta.atcoder.jp/contests/abc054/tasks/abc054_c

int main() {
    int N, M; cin >> N >> M;
    int path[8][8] = {};

    int a,b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        a--; b--;
        path[a][b] = 1;
        path[b][a] = 1;
    }

    int perm[N-1];
    for (int i = 1; i < N; i++) {
        perm[i - 1] = i;
    }

    int ans = 0;
    do {
        int now = 0;
        for (int i = 0; i < N - 1; i++) {
            if (path[now][perm[i]] == 0) break;
            now = perm[i];
            if (i == N-2) ans++;
        }
    } while(next_permutation(perm, perm + (N - 1)));

    cout << ans << "\n";

    return 0;
}
