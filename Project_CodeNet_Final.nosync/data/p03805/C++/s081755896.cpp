#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD=1e9+7;

int main(void){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> G(n,vector<int>(n,0));
    rep(i,m){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        G[a][b]=1;
        G[b][a]=1;
    }
    vector<int> X(n);
    rep(i,n) X[i]=i;
    int ans=0;
    do{
        if(X[0]!=0) continue;
        bool ok=true;
        rep(i,n-1){
            if(G[X[i]][X[i+1]]==0) ok=false;
        }
        if(ok) ans++;
    } while(next_permutation(X.begin(),X.end()));
    cout<<ans<<endl;
}