#define _DEBUG
//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
const ll INF=1e+18;
const int MOD=1e+9+7;

//デバッグ
#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0,a1,a2,a3,a4,x,...) x
#define debug1(x1) cout<<#x1<<": "<<x1<<endl
#define debug2(x1,x2) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<endl
#define debug3(x1,x2,x3) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<endl
#define debug4(x1,x2,x3,x4) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<endl
#define debug5(x1,x2,x3,x4,x5) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<", "#x5<<": "<<x5<<endl
#ifdef _DEBUG
#define debug(...) CHOOSE((__VA_ARGS__,debug5,debug4,debug3,debug2,debug1,~))(__VA_ARGS__)
#else
#define debug(...)
#endif

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

//省略
using vi  = vector<int>;
using vii = vector<vector<int>>;
using vl  = vector<ll>;
using vll = vector<vector<ll>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

// xのn乗%modを計算
ll mod_pow(ll x, ll n, ll mod){
    ll res = 1;
    while(n > 0){
        if(n & 1) res = res*x%mod;
        x = x*x%mod;
        n >>= 1;
    }
    return res;
}

int main(){
    ll N,X,M;
    cin>>N>>X>>M;
    ll cnt=1;
    vl deta(M,0);
    deta[X]++;
    ll ans=X;

    vl mdpow(M,0);
    REP(i,M){
        mdpow[i]=mod_pow(i,2,M);
    }

    while(true){
        X = mdpow[X];
        ans+=X;
        cnt++;

        if(cnt==N){
            cout<<ans<<endl;
            return 0;    
        }

        if(deta[X]!=0){
            break;
        }else{
            deta[X]++;
        }
    }
    ll one_loop=0;

    ll tmp=X;
    ll loop_sum=0;
    ll loop_size=0;

    do{
        X = mdpow[X];
        loop_sum+=X;
        loop_size++;
    }while(X!=tmp);

    ll loop_cnt=(N-cnt)/loop_size;

    cnt+=loop_cnt*loop_size;
    ans+=(loop_sum*loop_cnt);
    
    X = tmp;

    while(cnt<N){
        X = mdpow[X];
        ans+= X;
        cnt++;
    }
    cout<<ans<<endl;

}