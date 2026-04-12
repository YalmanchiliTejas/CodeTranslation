#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define REP(a,b) for(int a=0;a<(b);++a)
#define REP1(i,n) for(int i=1;i<=(n);++i)
#define debug(x) cerr<<#x<<": "<<x<<'\n'
#define all(x) (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define isYES(x) printf("%s\n",(x) ? "YES" : "NO")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define isYes(x) printf("%s\n",(x) ? "Yes" : "No")
#define isPossible(x) printf("%s\n",(x) ? "Possible" : "Impossible")
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define INF (1<<29)

// const long long INF = 1LL<<62;

#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
#define pie 3.14159265358979323846
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;
template<class T=int>
T in(){T x;cin>>x;return (x);}
template<class T>
void print(T& x){cout<<x<<'\n';}

const int MOD =(int)1e9+7;
// const int mod =(int)998244353;
const int mod =(int)1e9+7;

const int MAX =510000;
ll fac[MAX],finv[MAX],inv[MAX];
void COMint(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<MAX;i++){
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}
ll COM(int n,int k){
    if(n<k) return 0;
    if(n<0||k<0)return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}
ll gcd(ll a,ll b){
    if(a<0)a=-a;
    if(b<0)b=-b;
    if(b==0)return a;
    if(a>b){
        swap(a,b);
    }
    return gcd(a,b%a);
}
ll lcm(ll a,ll b){
  if(a<0)a=-a;
  if(b<0)b=-b;
    ll g;g=gcd(a,b);
    return b/g*a;
}
bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}
bool compare_by_a(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first){
        return a.first < b.first;
    }else{
        return a.second < b.second;
    }
}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
ll RS(ll N,ll P){
    if(P==0){
        return 1;
    }else{
        if(P%2==0){
            ll t=RS(N,P/2);
            return t*t;
        }else{
            return N*RS(N,P-1);
        }
    }
}
int main() {
  ios::sync_with_stdio(false);
  string N;cin>>N;
  int K=in();

  //桁DPで求める
  //dp_same[i][k]
  //左からi桁目までNと同じ数字で0でない数字がk個であるような数字の個数
  vector<vector<ll>>dp_same(N.length(),vector<ll>(4,0));
  //dp_less[i][k]
  //左からi桁目までN未満が確定している数字で0でない数字がk個であるような数字の個数
  vector<vector<ll>>dp_less(N.length(),vector<ll>(4,0));

    int d=(N[0]-'0');
    dp_same[0][1]=1;
    dp_less[0][1]=d-1;
    dp_less[0][0]=1;
    REP1(i,N.length()-1){
        int d=(N[i]-'0');
        if(d==0){
            REP(j,4){
                dp_same[i][j]+=dp_same[i-1][j];
                
                //0を入れる場合
                dp_less[i][j]+=dp_less[i-1][j];
                //0以外を入れる場合
                if(j>0)dp_less[i][j]+=dp_less[i-1][j-1]*9;
            }
        }else{
            REP(j,3){
                dp_same[i][j+1]+=dp_same[i-1][j];

                //dp_sameにd未満1以上の数字を付加
                dp_less[i][j+1]+=dp_same[i-1][j]*(d-1);
                //dp_lessに1以上9以下の数字を付加
                dp_less[i][j+1]+=dp_less[i-1][j]*9;
            }
            REP(j,4){
                dp_less[i][j]+=dp_less[i-1][j]+dp_same[i-1][j];
            }
        }
    }
  ll ans=0;
  ans+=dp_same[N.length()-1][K];
  ans+=dp_less[N.length()-1][K];
  cout<<ans<<endl;
  return 0;
} 
