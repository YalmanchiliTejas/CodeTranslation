#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> v;
    rep(i,n-1)v.push_back(i+1);
    sort(v.begin(), v.end());
    int ans = 0;
    do{
        bool flag = true;
        if(!count(G[0].begin(),G[0].end(),v[0])) flag = false;
        rep(i,n-2){
            if(count(G[v[i]].begin(), G[v[i]].end(), v[i+1]))continue;
            else{
                flag = false;
                break;
            }
        }
        if(flag)ans++;
    }while(next_permutation(v.begin(),v.end()));

    printf("%d\n", ans);
    return 0;
}