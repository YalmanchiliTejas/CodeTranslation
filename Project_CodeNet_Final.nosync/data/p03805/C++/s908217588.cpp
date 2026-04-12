#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define rer(i, a, b) for(int i = int(a) - 1; i >= int(b); i--)

using namespace std;

vector<int> G[8];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N,M;
    cin>>N>>M;
    rep(i,0,M){
        int a,b;
        cin>>a>>b;
        a--; b--;
        G[a].push_back(b); G[b].push_back(a);
    }
    int x[N];
    rep(i,0,N) x[i]=i;
    int ans=0;
    do{
        bool t=true;
        rep(i,0,N-1){
            if(find(G[x[i]].begin(),G[x[i]].end(), x[i+1])==G[x[i]].end()) t=false;
        }
        if(t) ans++;
    }while(next_permutation(x+1,x+N));
    cout <<ans <<"\n";
}
