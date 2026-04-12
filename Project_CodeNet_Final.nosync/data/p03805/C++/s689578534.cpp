#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <vector <int> > G;
int total = 1;
int N, M, ans = 0, freq[15];

void bkt(int node) {
    if(total == N) {
        ++ans;
    }
    else {
        freq[node] = 1;

        for(unsigned int z = 0; z < G[node].size(); ++z) {
            if(freq[G[node][z]] == 0) {
                ++total;
                bkt(G[node][z]);
                --total;
            }
        }

        freq[node] = 0;
    }
}

int main() {
   // #ifndef ONLINE_JUDGE
   // freopen("input.txt","r",stdin);
   // #endif // ONLINE_JUDGE

    cin >> N >> M;

    G.resize(N + 2);

    int x, y;
    for(int i = 1; i <= M; ++i) {
        cin >> x >> y;

        G[x].push_back(y);
        G[y].push_back(x);
    }

    bkt(1);

    cout << ans << '\n';

    return 0;
}
