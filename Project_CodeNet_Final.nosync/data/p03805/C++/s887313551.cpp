#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int g[10][10];

int main(){
    int n,m;
    cin>>n>>m;

    rep(i,m){
        int a,b;
        cin>>a>>b;
        a--,b--;
        g[a][b]=1;
        g[b][a]=1;
    }

    vector<int> ord(n);
    rep(i,n) ord[i]=i;
    int ans=0;

    do{
        if(ord[0]!=0) continue;
        bool ok=true;
        rep(i,n-1){
            if(g[ord[i+1]][ord[i]]==0){
                ok=false;
                break;
            }
        }
        if(ok) ans++;

    }while(next_permutation(all(ord)));

    cout<<ans<<endl;
}