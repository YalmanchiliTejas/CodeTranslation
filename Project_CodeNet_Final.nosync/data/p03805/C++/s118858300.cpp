#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define Rep(i, n) for (int i = 0; i < (int)(n); i++)
#define BitRep(i, n) for (int i = 0; i < (int)(1 << n); i++)
#define All(vec) vec.begin(), vec.end()
#define Sum(vec) accumulate(vec.begin(), vec.end(), 0)
#define Sort(vec) sort(vec.begin(), vec.end())
#define Reverse(vec) reverse(vec.begin(), vec.end())
#define Count(vec, x) count(vec.begin(), vec.end(), x)
#define Next_permutation(vec) next_permutation(vec.begin(), vec.end())
#define PI acos(-1)

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<bool>> graph(N, vector<bool>(N));
    Rep(i, M) {
        int a, b;
        cin >> a >> b;
        graph[a - 1][b - 1] = graph[b - 1][a - 1] = true;
    }
    vector<int> perm(N - 1);
    Rep(i, N - 1) perm[i] = i + 1;
    int ans = 0;
    do {
        int v = 0;
        bool flag = true;
        Rep(i, N - 1) {
            if (graph[v][perm[i]]) {
                v = perm[i];
            }
            else {
                flag = false;
                break;
            }
        }
        if (flag) ans++;
    } while (Next_permutation(perm));
    cout << ans << endl;
    return 0;
}