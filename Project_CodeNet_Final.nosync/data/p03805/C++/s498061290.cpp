#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
   
    int n,m; cin>>n>>m; vector<vector<int>> g(n);
    for (int i = 0; i < m; i++){
        int a,b; cin>>a>>b; a--; b--;
        g[a].push_back(b); g[b].push_back(a);
    }
    int a[n]; for (int i = 0; i < n; i++)a[i]=i;
    int ans=0;
    do{
        bool ok=true;
        for (int i = 0; i < n-1; i++){
            bool key=false;
            for (int j = 0; j < g[a[i]].size(); j++)key|=a[i+1]==g[a[i]][j];
            if(!key){ok=false; break;}
        }
        if(ok)ans++;
    }while(next_permutation(a+1,a+n));
    cout<<ans<<'\n';
}