#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edge(n,vector<int>(n,0));
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;a--;b--;
        edge[a][b]=1;
        edge[b][a]=1;
    }
    vector<int> perm;
    int ans=0;
    for(int i=1; i<n; i++) perm.push_back(i);
    do{
        bool flag = edge[0][perm[0]];
        for(int i=1; i<n-1; i++){
            flag = flag&&(edge[perm[i-1]][perm[i]]==1);
        }
        ans+=flag;
    }while(next_permutation(perm.begin(),perm.end()));
    cout<<ans;
    return 0;
}