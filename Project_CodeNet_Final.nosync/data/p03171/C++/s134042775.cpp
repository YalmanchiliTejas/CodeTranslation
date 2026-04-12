#include<iostream>
#include<map>
#include<vector>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm> 
#include<climits>
#include<stack>
#include<queue>
#include<set>
#include<cctype>
#include<bitset> 
#include<type_traits>
#include<numeric>
#include<array>
using namespace std;

# define REP(i,n) for (int i=0;i<(n);++i)
# define rep(i,a,b) for(int i=a;i<(b);++i)
# define p(s) std::cout << s ;
# define pl(s)  std::cout << s << endl;
# define printIf(j,s1,s2) cout << (j ? s1 : s2) << endl;
# define YES(j) cout << (j ? "YES" : "NO") << endl;
# define Yes(j) std::cout << (j ? "Yes" : "No") << endl;
# define yes(j) std::cout << (j ? "yes" : "no") << endl;
# define all(v) v.begin(),v.end()
# define showVector(v) REP(i,v.size()){p(v[i]);p(" ")} pl("")
template<class T> inline bool chmin(T &a, T b){ if(a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b){ if(a < b) { a = b; return true;} return false;}
typedef long long int ll;
typedef pair<int,int> P_ii;
typedef pair<double,double> P_dd;

template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}

template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

template<typename T,typename V>
typename enable_if<is_class<T>::value==0>::type
fill_v(T &t,const V &v){t=v;}

template<typename T,typename V>
typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t,const V &v){
  for(auto &e:t) fill_v(e,v);
}

const int mod = 1000000007;
const int MOD = 1000000007;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;

void addM(long long &a, long long b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

void mulM(long long &a, long long b) {
    a = ((a%MOD)*(b%MOD))%MOD ;
}

// a^b mod M
long myPow(long a,long b,int M) {
    long ret = 1;
    long tmp = a;
    while(b>0) {
        if((b&1)==1) ret = (ret * tmp) % M;
        tmp = (tmp * tmp) % M;
        b = b>>1;
    }
    return ret;
}

 // nCk mod M
int nCk(int n,int k,int M) {
    long ret = 1;
    int mi = min(k, n-k);
    for(int i=1;i<=mi;i++) {
        ret = (ret * myPow(i,M-2,M)) % M;
    }
    for(int i=n-mi+1;i<=n;i++) {
        ret = (ret * i) % M;
    }
    return (int)ret;
}

int N;

vector<int> a(3001);
auto dp = make_vec<ll>(3001,3001); 
auto flg = make_vec<int>(3001,3001); 

// [i,j]が残っている状態において、
// 左右どちらかを取った場合における(自分の総得点)-(相手の総得点)の最大値
// つまり、[i,j]対する問の答えになる
// 注：a[i]-dp[i-1]で常にどちらの手番であっても(自分の総得点)-(相手の総得点)になる
ll rec(int i,int j){
    if(flg[i][j]) return dp[i][j];

    flg[i][j]=1;
    if(i==j) return dp[i][j] = a[i];
    
    return dp[i][j] = max(a[i]-rec(i+1,j),a[j]-rec(i,j-1));
}

int main(){

    cin >> N;

    REP(i,N) cin >> a[i+1];
    fill_v(flg,0);

    pl(rec(1,N))
    
    return 0;
}