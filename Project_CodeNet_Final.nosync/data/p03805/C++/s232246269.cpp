#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(X) (X).begin(),(X).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
int g[11][11];
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> p;
    rep(i,n) p.push_back(i);
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a][b] = g[b][a] = 1;
    }
    int ans = 0;
    do{
        bool ok = true;
        if(p[0]!=0) break;
        for(int i = 1; i < n; ++i){
            if(g[p[i-1]][p[i]]!=1) ok = false;
        }
        if(ok) ++ans;
    }while(next_permutation(all(p)));
    cout << ans << endl;
    return 0;
}