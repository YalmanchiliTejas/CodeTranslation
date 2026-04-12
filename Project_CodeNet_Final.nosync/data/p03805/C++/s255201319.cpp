#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n, m; cin >> n >> m; 
    vector<vector<int>> G(n);
    rep(i,m){
        int a, b; cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> vec;
    rep(i,n) vec.push_back(i);
    int ans = 0;
    do{
        bool add = false;
        if(vec[0] != 0)continue;
        for(int i = 0; i < n-1; ++i){
            bool isOK = false;
            for(auto e : G[vec[i]]){
                if(e == vec[i+1]) isOK = true;
            }
            if(!isOK) break;
            if(i==n-2) add = true;
        }
        if(add) ans++;
    }while(next_permutation(ALL(vec)));
    cout << ans << endl;
}