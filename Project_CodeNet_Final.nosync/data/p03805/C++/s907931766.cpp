#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
//#define MOD 1000000007
const int INF = 1LL<<30;

int G[10][10];

int main() {
    int n,m;
    cin>>n>>m;

    rep(i,m){
        int a,b;
        cin>>a>>b;
        a--,b--;
        G[a][b]=1;
        G[b][a]=1;
    } 

    vector<int> ord(n);
    rep(i,n) ord[i]=i;

    int ans=0;
    do{
        if(ord[0]!=0) continue;
        bool ok=true;
        rep(i,n-1){
            if(G[ord[i]][ord[i+1]]==0) ok=false;
        }
        if(ok) ans++;
    }while(next_permutation(all(ord)));

    cout<<ans<<endl;

}