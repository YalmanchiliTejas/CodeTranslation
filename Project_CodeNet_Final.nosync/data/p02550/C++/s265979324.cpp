#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(i = 0; i < n; i++)
//2D::rep(i,j)rep(j,j)cin>>bin[i][j];
//vector<int> a(n)
#define Graph vector<vector<int>>
#define A1 cout<<"No"<<endl
#define A2 cout<<"Yes"<<endl
#define A3 cout<<ans<<
#define AA(i) cout<<i<<endl;
const int U=2e5+5;
const ll MOD=1000000007;
const int INF = 1001001001;

int main(){
    ll N; cin>>N;
    ll cou=0,i,X,M; cin>>X>>M;
    ll K=X;
    vector<bool> a(M,false);
    ll e=0;
    rep(i,M){
        if(a[X]) break;
        cou++;
        e+=X;
        a[X]=true;
        X=X*X%M;
    }
    ll cou2=0;
    ll b=0;
    rep(i,M){
        if(!a[X]) break;
        cou2++;
        b+=X;
        a[X]=false;
        X=X*X%M;
    }
    if(N<cou){
        ll ans=0;
        rep(i,N){
            ans+=K;
            K=K*K%M;
        }
        AA(ans);
    }
    else{
        ll c,d,ans=0;
        c = (N-cou)/cou2;
        d = (N-cou)%cou2;
        ans += c*b+e;
        rep(i,d){
            ans += X;
            X=X*X%M;
        }
        AA(ans);
    }
    return 0;
}