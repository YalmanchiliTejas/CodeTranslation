//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
const int INF=1e+9;
const int MOD=998244353;

//REPマクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define REP2(i,a,b) for(ll i=a;i<(ll)(b);i++)
#define REPD2(i,a,b) for(ll i=a;i>(ll)(b);i--)

// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

//vectorの扱い
#define ALL(x) (x).begin(),(x).end() //sortなどの引数省略
#define SIZE(x) ((ll)(x).size()) //size
#define MAX(x) *max_element(ALL(x)) //最大値
#define MIN(x) *min_element(ALL(x)) //最小値

const ll NUM=3010;
auto dp=make_vec<ll>(NUM,NUM,2);

int main(){
    ll N,S;
    cin>>N>>S;
    vector<ll> A(N);
    REP(i,N) cin>>A[i];

    
    REP(i,NUM) REP(j,NUM) REP(k,2) dp[i][j][k]=0;
    dp[0][0][1]=1;
    REP(i,N){
        dp[i+1][0][0]=dp[i][0][0]+dp[i][0][1];
        dp[i+1][0][1]=dp[i][0][1]+1;
        
    }
    REP(i,N){
        REP2(j,1,S+1){
            dp[i+1][j][0]=dp[i][j][0]+dp[i][j][1];
            dp[i+1][j][1]=dp[i][j][1];
            if(j-A[i]>=0) dp[i+1][j][1]+=dp[i][j-A[i]][1];
            dp[i+1][j][0]%=MOD;
            dp[i+1][j][1]%=MOD;
        }
    }

    cout<<(dp[N][S][0]+dp[N][S][1])%MOD<<endl;

}