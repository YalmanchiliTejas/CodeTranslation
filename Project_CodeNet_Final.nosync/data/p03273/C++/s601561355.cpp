#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const double EPS = 1e-10;
const ll mod=1000000007;
//const ll mod=998244353;

int main(void){
    ll h,w;
    char c[110][110];
    bool H[110]={},W[110]={};
    cin>>h>>w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>c[i][j];
            if(c[i][j]=='#'){
                H[i]=true;
                W[j]=true;
            }
        }
    }
    for(int i=0;i<h;i++){
        if(H[i]==false) continue;
        for(int j=0;j<w;j++){
            if(W[j]) cout<<c[i][j];
        }
        cout<<endl;
    }
}