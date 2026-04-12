#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int V = 204, src = V - 2, snk = V - 1;

int X(int v) {
    return v;
}
int Y(int v) {
    return 101 + v;
}

int A, B, E;
int D[12][12];
vector<pii> adj[V];

int main() {
    scanf("%d %d", &A, &B);

    for(int i = 1; i <= A; i++) {
        for(int j = 1; j <= B; j++) {
            scanf("%d", &D[i][j]);
        }
    }

    adj[src].push_back(pii(X(0), 0));
    adj[Y(0)].push_back(pii(snk, 0));

    for(int i = 0; i < 100; i++) {
        adj[ X(i) ].push_back(pii(X(i + 1), -1));
    }
    for(int i = 100; i >= 1; i--) {
        adj[ Y(i) ].push_back(pii(Y(i - 1), -2));
    }

    for(int i = 1; i <= A; i++) {
        for(int j = 1; j <= B; j++) {

            bool f = false;
            for(int a = 0; a <= 100 / i; a++) {
                for(int b = 0; b <= 100 / j; b++) {
                    int c = D[i][j] - a * i - b * j;
                    if(c < 0) continue;

                    bool ok = true;
                    for(int x = 1; x <= A; x++) {
                        for(int y = 1; y <= B; y++) {
                            if(D[x][y] > a * x + b * y + c) {
                                ok = false;
                                break;
                            }
                        }
                    }

                    if(ok) {
                        adj[X(a)].push_back(pii(Y(b), c));
                        f = true;
                        break;
                    }
                }
                if(f) break;
            }

            if(!f) {
                printf("Impossible");
                return 0;
            }
        }
    }

    printf("Possible\n");

    E = 0;
    for(int u = 0; u < V; u++) {
        sort(adj[u].begin(), adj[u].end());

        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;

            if(i == 0 || adj[u][i - 1] != adj[u][i]) {
                E++;
            }
        }
    }

    printf("%d %d\n", V, E);
    for(int u = 0; u < V; u++) {
        sort(adj[u].begin(), adj[u].end());

        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;

            if(i == 0 || adj[u][i - 1] != adj[u][i]) {
                if(w == -1) printf("%d %d X\n", u + 1, v + 1);
                else if(w == -2) printf("%d %d Y\n", u + 1, v + 1);
                else printf("%d %d %d\n", u + 1, v + 1, w);
            }
        }
    }

    printf("%d %d", src + 1, snk + 1);
}
