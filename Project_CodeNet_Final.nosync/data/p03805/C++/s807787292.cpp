#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll=long long;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;
using Graph = vector<vector<int>>;

int main(){
    int n,m;cin >> n >> m;
    Graph G(n+1);
    vector<vector<bool>> p(n+1,vector<bool>(n+1,false));
    rep(i,m){
        int a,b;cin>>a>>b;
        p[a][b] = true;
        p[b][a] = true;
    }
    vector<int> v;
    rep(i,n){
        v.push_back(i+1);
    }
    int cnt=0;
    do{
        bool yes=true;
        if(v[0]!=1) continue;
        rep(i,n-1){
            if(!p[v[i]][v[i+1]]){
                yes = false;
                break;
            }
        }
        if(yes) cnt++;
    }while(next_permutation(v.begin(),v.end()));
    cout << cnt << endl;
}