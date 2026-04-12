#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<deque>
#include<map>
#include<bitset>

using namespace std;
using ll = long long;

#define rep(i, n) for(int i = 0;i < (n);i++)
#define repr(i, n) for(int i = (n);i >= 0;i--)
#define repf(i, m, n) for(int i = (m);i < (n);i++)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;} return 0;}
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
//////////////////////////////////////////////////


int a[30], b[30];
int perm[30];

int main() {
    int n, m, a, b, res = 0;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>());
    rep (i, m) {
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    rep (i, n)
        perm[i] = i;

    do {
        rep (i, n) {
            if (i == n - 1) res++;
            if (count(graph[perm[i]].begin(), graph[perm[i]].end(), perm[i+1]) == 0)
                break;
        }
    } while (next_permutation(perm + 1, perm + n));
    cout << res << endl;
    return 0;
}
