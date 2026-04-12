#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> P;
typedef priority_queue<P,vector<P>,greater<P>> P_queue;

const ll MOD=998244353;
const ll mod=1000000007;
const ll INF=1e18;
const double PI=3.1415926535897932;
vec dx={1,0,-1,0};
vec dy={0,1,0,-1};

#define REP(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end());
#define ADD(a,b) a=(a+b)%MOD


ll dp[3001];

int main(){
    ll N,S; cin>>N>>S;
    vec d(N);
    rep(i,N) cin>>d[i];
    ll ans=0;
    rep(i,N) {
        if(d[i]==S) ADD(ans,(i+1)*(N-i));
        if(d[i]<S) {
            ADD(ans,dp[S-d[i]]*(N-i)%MOD);
            for(int j=S-d[i]-1; j>0; j--){
                ADD(dp[j+d[i]],dp[j]);
            }
            ADD(dp[d[i]],i+1);
        }
    }
    cout<<ans<<endl;
}