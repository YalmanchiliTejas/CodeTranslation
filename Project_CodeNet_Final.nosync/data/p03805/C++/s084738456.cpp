#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define loop(i, a, b) for (int i = a; i < (int)(b); i++)


int N, M;
int edge[50][50];
bool visited[10];

int search(int curr, int step) {
    if (step == N) {
        return 1;
    }
    int pattern = 0;
    visited[curr] = true;
    rep(i, N) {
        if (edge[curr][i] > 0 && !visited[i]) {
            pattern += search(i, step + 1);
        }
    }
    visited[curr] = false;
    return pattern;
}

int main(){
    cin >> N >> M;
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        edge[a][b] = 1;
        edge[b][a] = 1;
    }
    int count = search(0, 1);
    cout << count << endl;
    return 0;
}