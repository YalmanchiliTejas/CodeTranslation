#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int N, M; cin >> N >> M;
    set<int> to[N];
    rep(i, M){
        int a, b; cin >> a >> b;
        a--; b--;
        to[a].insert(b);
        to[b].insert(a);
    }
    vector<int> V;
    for (int i = 1; i < N; i++){
        V.push_back(i);
    }

    int ans = 0;
    do {
        bool ch = true;
        int a = V[0];
        if(!to[0].count(a)){
            continue;
        }
        for (int i = 0; i < V.size()-1; i++){
            if(!to[V[i+1]].count(V[i])){
                ch = false;
                break;
            }
        }
        if(ch)ans++;
    } while(next_permutation(V.begin(), V.end()));

    cout << ans << endl;



    return 0;
}