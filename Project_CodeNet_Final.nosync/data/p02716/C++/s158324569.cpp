#include<bits/stdc++.h>
//using namespace std;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<=(int)(n);i++)
#define per(i,j,n) for(int i=(int)(j);(int)(n)<=i;i--)
#define ll long long
#define ALL(a) (a).begin(),(a).end()
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(int)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(int)(key)))
#define pb push_back
#define mp make_pair
#define endl "\n"
using std::cin;
using std::cout;
using std::vector;
using std::pair;
using std::string;
using std::upper_bound;
using std::lower_bound;
using vi=vector<ll>;
using vii=vector<vi>;
using pii=pair<ll,ll>;
const ll MOD=1e9+7;
const int MAX=1e5+1;
const ll INF=(1ll<<62)-1;
signed main(){
    int N; cin>>N;
    vi A(N);
    rep(i,0,N) cin>>A[i];
    int siz=2+N%2;
    vii dp(N+1,vi(siz,-INF));
    dp[0][0]=0;
    REP(i,1,N){
        rep(j,0,siz){
            dp[i][j]=dp[i-1][j];
            if(j%2!=i%2){
                dp[i][j]+=A[i-1];
            }
        }
        rep(j,0,siz-1){
            if(i%2==j%2&&i>j+1){
                if(i==j+2) dp[i][j+1]=A[i-1];
                else dp[i][j+1]=std::max(dp[i][j+1],dp[i-j-2][j]+A[i-1]);
            }
        }
    }
    ll ans=dp[N-1][0];
    rep(i,1,siz) ans=std::max(dp[N][i],ans);
    cout<<ans<<endl;
}
 
