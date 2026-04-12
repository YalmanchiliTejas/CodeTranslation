#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int N; cin >> N;
    int M; cin >> M;
    vector<vector<bool>> E(N,vector<bool>(N));
    for (int i=0;i<M;i++){
        int a,b; cin >> a >> b;
        --a; --b;
        E[a][b] = true;
        E[b][a] = true;
    }
    vector<int> order(N);
    for (int i=0;i<N;i++) order[i] = i;
    int res = 0;
    do {
        if (order[0]!=0) continue;
        bool can = true;
        for (int i=0;i<N-1;i++){
            if (!(E[order[i]][order[i+1]])) can = false;
        }
        if (can) res++;
    }while(next_permutation(order.begin(),order.end()));
    cout << res << endl;
    return 0;
}
