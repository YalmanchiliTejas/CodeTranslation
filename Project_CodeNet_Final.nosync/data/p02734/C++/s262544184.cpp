#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> P;
typedef priority_queue<P,vector<P>,greater<P>> P_queue;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end());

const ll MOD=998244353;
const ll mod=1000000007;
const ll INF=1e15;
vec dx={1,0,-1,0};
vec dy={0,1,0,-1};

ll dp[3001];
int main(){
    ll N,S; cin>>N>>S;
    vec d(N);
    rep(i,N) cin>>d.at(i);
    dp[0]=1;
    //ll ans=0;
    rep(i,N){
        ll x=d.at(i);
        if(x<=S){
            for(ll j=S-x;j>=0;j--){
                ll K=1;
                if(j==S-x) K=(K*(N-i))%MOD;
                if(j==0) K=(K*(i+1))%MOD;
                dp[j+x]=(dp[j]*K+dp[j+x])%MOD;
            }
        }
    }
    
    cout<<dp[S]<<endl;
}