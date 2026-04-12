#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;
using Graph = vector<vector<int>>;
int main() {
    int N, M; cin >> N >> M;
    Graph G(N);
    rep(i,M) {
        int a, b; cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }
    vector<int> vec;
    for(int i = 0; i < N; i++) {
        vec.push_back(i);
    }
    int ans = 0;
    do {
        // cout << "===========" << endl;
        // cout << vec[0] << endl;
        if(vec[0] != 0) continue;
        // cout << vec[0] << endl;
        bool flag = true;
        for(int i = 0; i < N; i++) {
            if(i != (N-1)) {
                vector<int> mm = G[vec[i]];
                auto itr = find(mm.begin(), mm.end(), vec[i+1]);
                if(itr == mm.end()) flag = false;
            }
        }
        if (flag) ans++;

    } while(next_permutation(vec.begin(), vec.end()));
    cout << ans << endl;

    return 0;
}
