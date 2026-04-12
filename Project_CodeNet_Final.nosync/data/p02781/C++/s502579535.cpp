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

string s;int K;
int comb(int n,int k){
    if(k<0||n<k)return 0;

    if(k==1)return n;
    else if(k==2)return n*(n-1)/2;
    else return n*(n-1)*(n-2)/6;
}

int solve(bool smaller,int i,int k){
    int n=s.size();
    if(i==n){
        if(k==0)return 1;
        else return 0;
    }
    if(k==0)return 1;

    if(smaller){
        return comb((n-i),k)*pow(9,k);
    }
    else{
        int v=s.at(i)-'0';
        if(v==0){
            return solve(false,i+1,k);
        }
        else {
        int aida,zero,pitta;
        aida=solve(true,i+1,k-1)*(v-1);
        zero=solve(true,i+1,k);
        pitta=solve(false,i+1,k-1);
        return aida+zero+pitta;
        }
    }
}
int main( ){
    cin>>s>>K;
    ll ans=0;
    ans=solve(false,0,K);
    cout<<ans<<endl;
    return 0;
}


