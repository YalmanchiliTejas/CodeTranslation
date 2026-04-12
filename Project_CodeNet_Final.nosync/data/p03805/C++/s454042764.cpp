#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define dunk(a) cout << (a) << endl
#define rall(a) (a).rbegin(),(a).rend()
using namespace std;
typedef long long ll;

// グラフの用意
bool G[10][10];

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n), b(n), v(n);

    rep(i,n){
        v[i] = i;
    }

    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--; b--;

        G[a][b] = G[b][a] = true;
    }

    int ans = 0;

    do{
        bool jud = true;

        if(v[0] !=0) break;

        for(int i=0; i<n-1; i++){
            if(!G[v[i]][v[i+1]]){
                jud = false;
                break;
            }
        }

        if(jud) ans++;

    }
    while(next_permutation(all(v)));

    dunk(ans);
}