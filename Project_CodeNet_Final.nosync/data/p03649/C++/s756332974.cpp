//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
const ll INF=2e+16;
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
    ll N;
    cin>>N;
    vector<ll> a(N);
    REP(i,N) cin>>a[i];
    sort(ALL(a));
    ll l=-1;
    ll r=INF;
    while(r-l>1){
        ll mid=(l+r)/2;
        ll x=mid*N;
        ll cnt=0;
        REP(i,N){
            ll tmp=x+a[i]-(N-1);
            ll n;
            if(tmp<=0) n=0;
            else n=(tmp-1)/(N+1)+1;
            cnt+=n;
        }
        if(x>=cnt) r=mid;
        else l=mid;
    }

    ll ans;
    
    REP(i,200*N+1){
        ll x=N*(l-100)+i;
        if(x<0) continue;
        ll cnt=0;
        REP(i,N){
            ll tmp=x+a[i]-(N-1);
            ll n;
            if(tmp<=0) n=0;
            else n=(tmp-1)/(N+1)+1;
            cnt+=n;
        }
        if(x>=cnt){
            ans=x;
            break;
        }
    }
    cout<<ans<<endl;
}