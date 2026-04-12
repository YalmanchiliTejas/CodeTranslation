#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define int long long
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int N, X;
vector<int> maisu;
vector<int> maxmaisu;

// l:レベル, x:下から層
int burger(int l, int x){
    if(x == maisu[l]){
        return maxmaisu[l];
    }
    if(x == 1) {
        return 0;
    }
    int han = maisu[l] / 2;
    if(x == han + 1){
        return maxmaisu[l - 1] + 1;
    }
    if(x <= han){
        return burger(l - 1, x - 1);
    }
    if(x > han + 1){
        return maxmaisu[l - 1] + 1 + burger(l - 1, x - (han + 1));
    }
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> X;
    maisu.resize(N + 1);
    maxmaisu.resize(N + 1);
    maisu[0] = 1;
    for (int i = 0; i < N; ++i) {
        maisu[i + 1] = maisu[i] * 2 + 3;
    }
    maxmaisu[0] = 1;
    for (int i = 0; i < N; ++i) {
        maxmaisu[i + 1] = maxmaisu[i] * 2 + 1;
    }
    int ans = burger(N, X);
    cout << ans << endl;
}