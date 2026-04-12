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
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define MOD 1000000007

#define REP(i,n) for(int i=0;i<n;i++)
#define REPS(i,f,n) for(int i=(f);i<(n);i++)
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define debug(x) #x << "=" << (x)

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

int A[105][105] = {};

int main() {
    int N, M; cin >> N >> M;
    int a, b;
    REP(i, M) {
        cin >> a >> b;
        A[a][b] = 1;
        A[b][a] = 1;
    }

    vector<int> perm(N-1);
    REPS(i, 2, N+1) {
        perm[i-2] = i;
    }
    sort(perm.begin(), perm.end());

    int ans = 0;
    do {
        int current = 1;
        for (int i = 0; i < perm.size(); i++) {
            if (!A[current][perm[i]]) break;
            current = perm[i];
            if (i == perm.size()-1) ans++;
        }
    } while(next_permutation(perm.begin(), perm.end()));

    cout << ans << "\n";

    return 0;
}
