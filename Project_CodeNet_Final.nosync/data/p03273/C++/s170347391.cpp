#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;
ll gcd(ll a, ll b){if(b==0) return a; return gcd(b, a%b);}
int main(){
    fast_io

    int h, w;
    cin>>h>>w;
    char a[h][w];
    bool flagh[h]={false};
    bool flagw[w]={false};
    rep(i, h){
        rep(j,w){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<h;i++){
        bool flag=true;
        for(int j=0;j<w;j++){
            if(a[i][j]=='#') flag=false;
        }
        if(flag) flagh[i]=true;
    }

    for(int j=0;j<w;j++){
        bool flag=true;
        for(int i=0;i<h;i++){
            if(a[i][j]=='#') flag=false;
        }
        if(flag) flagw[j]=true;
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(flagw[j] || flagh[i]){}
            else{
                cout<<a[i][j];
            }
        }
        
        if(flagh[i]==false)cout<<endl;
    }
    return 0;
}