#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
using vll=vector<ll>;
using vi=vector<int>;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

//pow(llpow,modpow)
template<class T> ll llpow(ll x,T n){ll ans=1;if(x==0)ans=0;while(n){if(n&1)ans*=x;x*=x;n>>=1;}return ans;}
long long modpow(long long a, long long n, long long mod) {long long res = 1;while (n > 0) {if (n & 1) res = res * a % mod;a = a * a % mod;n >>= 1;}return res;}
//最大公約数
template<class T> inline T gcd(T x,T y){if(y==0)return x; else {return gcd(y,x%y);}}
//最小公倍数
template<class T> inline T lcm(T x,T y){return x/gcd(x,y)*y;}
//逆元
long long modinv(long long a, long long m) {long long b = m, u = 1, v = 0;while (b) {long long t = a / b;a -= t * b; swap(a, b);u -= t * v; swap(u, v);}u %= m;if (u < 0) u += m;return u;}

#define rep(i,n) for(ll i=0;i<(ll)n;i++)
#define rep2(i, begin_i, end_i) for (ll i = (ll)begin_i; i < (ll)end_i; i++)

long long INF = 1LL<<60;
int main( ){
    string num;
    cin>>num;
    int K;
    cin>>K;
    //same(true 0,false 1),num_of_digit(100),num_of_notzero(3)
    int dp[101][4][2]={0};
    //何も決めてない状態
    dp[0][0][0]=1;
    rep(i,num.size()){
            rep(j,4){
                rep(k,2){
                    rep(d,10){
                    int nd=num[i]-'0';
                    int ni=i+1,nj=j,nk=k;
                    if(d!=0)nj++;
                    if(nj>K)continue;
                    //ここnkじゃなくてkなことに注意．．．
                    if(k==0){
                        if(nd>d)nk=1;
                        if(d>nd)continue;
                    }
                    dp[ni][nj][nk]+=dp[i][j][k];
                    }
                }
            }
    }
    int n=num.size();
    cout<<dp[n][K][0]+dp[n][K][1]<<endl;
    return 0;
}


