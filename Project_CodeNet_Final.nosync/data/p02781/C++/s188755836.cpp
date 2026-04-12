#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n; i>-1; --i)
#define ALL(a) (a).begin(),(a).end()
#define FILL(a,n,x); REP(i,(n)){ (a)[i]=(x); }
#define CINA(a,n); REP(i,(n)){ cin >> (a)[i]; }
#define FILL2(a,n,m,x); REP(i,(n)){ REP(j,(m)){(a)[i][j]=(x);} }
#define CINA2(a,n,m); REP(i,(n)){ REP(j,(m)){cin >> (a)[i][j];} }
#define Liny "Yes\n"
#define Linn "No\n"
#define LINY "YES\n"
#define LINN "NO\n"

//cout << setfill('0') << right << setw(4) << 12; // "0012"
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
int keta_wa(ll x){ if(x<10){return x;} else{return keta_wa(x/10) + x%10;} }
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
int __stoi(string s){ return atoi(s.c_str()); }
ll sum(ll a[],ll N){ return accumulate(a,a+N,0LL);}
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a/gcd(a,b)*b;}
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
template<class T> void chmin(T& a, T b){ if(a>b){a=b;} }
template<class T> bool isIn(T a,vector<T> v){ for(T x:v){ if(a==x){return true;}} return false;}
string strReplace(string s,string target, string replacement){
    if (!target.empty()) {
      std::string::size_type pos = 0;
      while ((pos = s.find(target, pos)) != std::string::npos) {
        s.replace(pos, target.length(), replacement);
        pos += replacement.length();
      }
    }
    return s;
}
const ll MOD = 1e9+7;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MP make_pair

bool DEBUG = 0;

ll dp[101][2][5]; // dim, 確定フラグ, 0じゃない数の数

int main(){
    string s; cin>>s;
    int L = s.size();
    int K; cin>>K;
    
    REP(d,101) REP(flag,2) REP(k,5) dp[d][flag][k] = 0LL;
    dp[0][0][0] = 1;
    REP(d,L){
        REP(flag,2){
            REP(k,4){
                int x = ctoi(s[d]);
                REP(i,10){ // 注目している座を0から9で埋める
                    if(x < i && flag==0){ continue; } // 未確定かつ大きい場合はあり得ない
                    
                    ll flag2 = (i<x || flag); // 進む先の小ささは確定しているか
                    ll k2 = k; // 進む先の0じゃない数の数
                    if(i != 0){ ++k2; } //0じゃない場合k2は増える
                    
                    dp[d+1][flag2][k2] += dp[d][flag][k];
                }
            }
        }
    }
    ll ans = dp[L][0][K] + dp[L][1][K];
    cout << ans << "\n";
}