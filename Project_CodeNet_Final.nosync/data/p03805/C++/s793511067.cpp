#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

bool G[10][10];

int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b; a--; b--;
        G[a][b] = G[b][a] = true;
    }
    vector<int> v(n);
    rep(i,n) v[i] = i;
    int res = 0;
    do{
        if(v[0] != 0) break;
        bool ok = true;
        for(int i = 0; i+1 < n; i++){
            int from = v[i];
            int to = v[i+1];
            if(!G[from][to]) ok = false;
        }
        if(ok) res++;
    }while(next_permutation(v.begin(),v.end()));
    cout << res << endl;
    return 0;
}