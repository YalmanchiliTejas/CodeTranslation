#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

const int INF = 1 << 30;
const ll LLINF = 1LL << 62;

int mod = 1000000007;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M; cin >> N >> M;
    vector<int> nodes[N];
    rep(i, M){
        int a, b; cin >> a >> b;
        a--; b--;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
    vector<int> v(N);
    rep(i, N) v[i] = i;
    int ans = 0;
    do{
        bool ok = true;
        for(int i = 0; i < N-1; i++){
            bool reach = false;
            int to = v[i+1];
            rep(j, nodes[v[i]].size()) if(to == nodes[v[i]][j]) reach = true;
            if(!reach) ok = false;
        }
        if(ok) ans++;
    }while(next_permutation(v.begin()+1, v.end()));
    cout << ans << endl;
    return 0;
}