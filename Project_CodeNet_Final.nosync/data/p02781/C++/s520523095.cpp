//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
const int INF=1e+9;
const int MOD=1e+9+7;

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

int main(){
    string N;
    int K;
    cin>>N>>K;
    int SIZE=N.size();
    auto dp = make_vec<ll>(SIZE+1,2,K+1);
    REP(j,2){
        REP(k,K+1){
            dp[0][j][k]=0;
        }
    }
    dp[0][0][0]=1;
    REP(i,N.size()){
        REP(j,2){
            REP(k,K+1){
                REP(x,j ? 10 : N[i]-'0'+1){
                    if(x==0){dp[i+1][j||x<(N[i]-'0')][k]+=dp[i][j][k];}
                    else if(k>=1){
                        dp[i+1][j||x<(N[i]-'0')][k]+=dp[i][j][k-1];
                    }
                }
            }
        }
    }
    cout<<(dp[SIZE][0][K]+dp[SIZE][1][K])<<endl;
    
}