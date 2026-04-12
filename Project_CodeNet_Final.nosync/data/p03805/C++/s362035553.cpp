#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())


int N, M;
vi used;
vvi edges;

int dp(int now, int length){
    if (used[now]) return 0;
    if (length == N) return 1;

    int ans=0;
    used[now] = 1;

    for (int i = 0; i < N; i++) {
        if (edges[now][i]) {
            ans += dp(i, length+1);
        }
    }

    used[now] = 0;

    return ans;
}

void solve(){
    cin >> N >> M;
    used = vi(N,0);
    edges = vvi(N, vi(N,0));

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges[a][b] = 1;
        edges[b][a] = 1;
    }


    cout << dp(0, 1) << endl;

    return;
}

int main(int argc, char const* argv[])
{
    solve();
    return 0;
}
