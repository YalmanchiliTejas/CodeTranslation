#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<string,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
ll INF=1LL<<60;


//dp[i][j]は左i右j削られた後のX-Y
vector<vector<ll>> dp(3001, vector<ll>(3001, INF));
ll N;
vector<ll> a(3001,0);

ll F(ll x,ll y){
    if(dp[x][y]!=INF)return dp[x][y];
    if(x+y==N){return dp[x][y]=0;}


    //Taroから
    if((x+y)%2==0){
        ll ans;
        ans=max(a[x]+F(x+1,y),a[N-y-1]+F(x,y+1));
        return dp[x][y]=ans;
    }
    //Jiroから
    else{
        ll ans;
        ans=min(-a[x]+F(x+1,y),-a[N-y-1]+F(x,y+1));
        return dp[x][y]=ans;
    }

}

int main(){
    cin >> N;
    for(ll i=0;i<N;i++){
        cin>>a[i]
    ;}

    cout<<F(0,0)<<endl;

    return 0;
}
