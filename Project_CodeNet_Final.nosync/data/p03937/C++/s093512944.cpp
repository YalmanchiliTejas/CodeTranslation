#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9;
const ll INF=4e18;
const ll dy[4]={1,0,-1,0};
const ll dx[4]={0,-1,0,1};
int main(){
    int H,W;cin>>H>>W;
    char c[H][W];
    int sum=0;
    rep(i,H)rep(j,W){
        cin>>c[i][j];
        if(c[i][j]=='#')sum++;
    }
    int h=0,w=0,cnt=0;
    while(true){
        if(h<H-1){
            if(c[h+1][w]=='#')h++,cnt++;
            else if(w<W-1){
                if(c[h][w+1]=='#')w++,cnt++;
                else break;
            }
            else break;
        }
        else if(w<W-1){
            if(c[h][w+1]=='#')w++,cnt++;
            else break;
        }
        else break;
    }
    if(sum==H+W-1 and cnt==sum-1 and h==H-1 and w==W-1)cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
    return 0;
}