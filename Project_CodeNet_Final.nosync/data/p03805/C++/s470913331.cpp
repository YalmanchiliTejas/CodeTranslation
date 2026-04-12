#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

template <class T>
inline bool chmin(T& a, T b)
{
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T& a, T b)
{
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

typedef long long ll;

#define MAX_N 10000

struct Edge {
    int to;
    int weight;
    Edge(int t, int w)
        : to(t)
        , weight(w)
    {
    }
};
using Graph = vector<vector<int>>;
using Graph_e = vector<vector<Edge>>;

vector<int> dx = { 1, 0, -1, 0 };
vector<int> dy = { 0, 1, 0, -1 };
typedef pair<int, int> P;

bool G[10][10];

int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        G[a][b] = G[b][a] = true;
    }

    // Permutation
    vector<int> ord(N);
    for (int i = 0; i < N; i++)
        ord[i] = i;

    // try permutation
    int res = 0;
    do {
        if (ord[0] != 0) // スタートは0限定
            break;

        bool ok = true;
        for (int i = 0; i + 1 < N; i++) {
            int from = ord[i];
            int to = ord[i + 1];
            if (!G[from][to])
                ok = false;
        }
        if (ok)
            res++;
    } while (next_permutation(ord.begin(), ord.end()));

    cout << res << endl;
}
