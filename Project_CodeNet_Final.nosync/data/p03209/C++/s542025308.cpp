#include <bits/stdc++.h>
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
typedef pair<ll,ll> P_ii;
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
};

int main() {
    ll N,X;cin >> N >> X;

    vector<ll> L(N+1),P(N+1);
    L[0]=1;
    P[0]=1;
    REP(i,N){
        L[i+1] = L[i]*2+3;
        P[i+1] = P[i]*2+1;        
    }

    ll ans=0;
    ll now_x=1;
    ll now_n=N-1;
    while(1){
        if(now_x == X) {
            // 左端のB
            break;

        } else if(now_x + L[now_n] >= X) {
            // 左側のL-1
            now_x += 1;
            now_n -= 1;            
            if(now_n < 0) {
                ans += 1;
                break;
            }

        } else if (now_x + L[now_n] + 1 == X){
            // 中央のP
            ans += P[now_n] + 1;
            break;

        } else if (now_x + L[now_n] + 1 + L[now_n] >= X){
            // 右側のL-1
            ans += P[now_n] + 1;
            now_x += 1 + L[now_n] + 1;
            now_n -= 1;            
            if(now_n < 0) {
                ans += 1;
                break;
            }

        } else {
            // 右端のB
            ans += P[now_n] + 1 + P[now_n];
            break;
        } 
    }

    pl(ans)

    return 0;
}