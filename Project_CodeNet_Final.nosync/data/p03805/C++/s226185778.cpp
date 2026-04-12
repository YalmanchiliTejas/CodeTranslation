#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main() {
    int n, m;
    cin >> n >> m;
    Graph G(n);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        --a; --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int ans=0;
    vector<int> v(n-1);
    rep(i,n-1) v[i]=i+1;
    do {
        int pr=0;
        for(int i=0; i<n-1; i++){
            bool ok=false;
            for(auto u : G[pr]){
                if(u==v[i]) ok=true;
            }
            if(ok && i==n-2){
                ++ans;
            }else if(ok && i!=n-2){
                pr=v[i];
            }else{
                break;
            }
        }
    } while(next_permutation(v.begin(),v.end()));
    cout << ans << "\n";
    return 0;
}