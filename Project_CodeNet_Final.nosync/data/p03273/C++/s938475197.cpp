#include<bits/stdc++.h>
#define INFTY 1<<20
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const int MOD=1000000007;
int n;
int x[102],cnt=0;
//最大公約数
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
int main(){
    int h,w;cin>>h>>w;
    char a[h][w];
    int hl[h],wl[w];
    rep(i,h)rep(j,w)cin>>a[i][j];
    int ok=1;
    rep(i,h){
        ok=1;
        rep(j,w){
            if(a[i][j]=='.')continue;
            else {hl[i]=1;ok=0;break;}
        }
        if(ok)hl[i]=0;
    }
    rep(i,w){
        ok=1;
        rep(j,h){
            if(a[j][i]=='.')continue;
            else {wl[i]=1;ok=0;break;}
        }
        if(ok)wl[i]=0;
    }

    rep(i,h){
        if(hl[i]){
            rep(j,w){
                if(wl[j])cout<<a[i][j];
            }
        }
        else continue;
        cout<<endl;
    }
return 0;
}