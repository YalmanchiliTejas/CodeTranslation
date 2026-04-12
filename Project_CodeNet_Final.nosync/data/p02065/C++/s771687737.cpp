#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto& (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define sar(a,n) {cout<<#a<<":";rep(pachico,n)cout<<" "<<a[pachico];cout<<endl;}

using namespace std;

template<typename S,typename T>auto&operator<<(ostream&o,pair<S,T>p){return o<<"{"<<p.fi<<","<<p.se<<"}";}
template<typename T>auto&operator<<(ostream&o,set<T>s){for(auto&e:s)o<<e<<" ";return o;}
template<typename S,typename T,typename U>
auto&operator<<(ostream&o,priority_queue<S,T,U>q){while(!q.empty())o<<q.top()<<" ",q.pop();return o;}
template<typename K,typename T>auto&operator<<(ostream&o,map<K,T>&m){for(auto&e:m)o<<e<<" ";return o;}
template<typename T>auto&operator<<(ostream&o,vector<T>v){for(auto&e:v)o<<e<<" ";return o;}
void ashow(){cout<<endl;}template<typename T,typename...A>void ashow(T t,A...a){cout<<t<<" ";ashow(a...);}
template<typename S,typename T,typename U>
struct TRI{S fi;T se;U th;TRI(){}TRI(S f,T s,U t):fi(f),se(s),th(t){}
bool operator<(const TRI&_)const{return(fi==_.fi)?((se==_.se)?(th<_.th):(se<_.se)):(fi<_.fi);}};
template<typename S,typename T,typename U>
auto&operator<<(ostream&o,TRI<S,T,U>&t){return o<<"{"<<t.fi<<","<<t.se<<","<<t.th<<"}";}

typedef pair<int, int> P;
typedef pair<ll, ll> pll;
typedef TRI<int, int, int> tri;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<P> vp;
typedef vector<double> vd;
typedef vector<string> vs;

const int MAX_N = 100005;

int MOD;

inline int mod_pow(int a, ll b)
{
    int res = 1;
    while(b){
        if(b & 1){
            res = (ll)res * a % MOD;
        }
        a = (ll)a * a % MOD;
        b >>= 1;
    }
    return res;
}

inline int add(int x,int y)
{
    return (x + y)%MOD;
}

inline int sub(int x,int y)
{
    return (x+MOD-y)%MOD;
}

inline int mul(int x,int y)
{
    return (ll)x*y%MOD;
}

int dp[105][205][(1 << 10)];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, K;
    cin >> n >> K >> MOD;
    dp[1][1][1] = 1;
    srep(i,1,n+1){
        srep(j,i,2*n){
            int l = j-i;
            rep(k,(1 << K)){
                if(dp[i][j][k] == 0) continue;
                if(l == i){
                    if(k == 0) continue;
                    int tmp = (k & ((1<<(K-1))-1));
                    dp[i+1][j+1][(tmp<<1)+1] = add(dp[i+1][j+1][(tmp<<1)+1], dp[i][j][k]);
                    continue;
                }
                // 右を増やす
                int hoge = i-l;
                int migi = INF;
                int hidari = INF;
                bool flag = false;
                rep(l,K){
                    if(k>>l&1){
                        hoge--;
                        if(hoge == 0){
                            migi = j-l;
                        }
                    }else{
                        if(!flag){
                            flag = true;
                            hidari = j-l;
                        }
                    }
                }
                if(hidari == INF){
                    hidari = j-K;
                }
                if(i == j){
                    hidari = 1;
                }
                // assert(migi != INF);
                // cmn(hidari, j-K), cmn(migi, j-K);
                // cout << i << " " << j << " " << hidari << " " << migi << "\n";
                int tmp = (k & ((1<<(K-1))-1));
                dp[i][j+1][(tmp<<1)] = add(dp[i][j+1][(tmp<<1)], dp[i][j][k]);
                if(j+1-hidari == K || j+1-migi == K) continue;
                dp[i+1][j+1][(tmp<<1)+1] = add(dp[i+1][j+1][(tmp<<1)+1], dp[i][j][k]);
            }
        }
    }
    int ans = 0;
    rep(i,(1 << K)){
        ans = add(ans, dp[n][2*n][i]);
    }
    cout << ans << "\n";
    return 0;
}

