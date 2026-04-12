#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define si(X) scanf("%d", &(X))
#define sll(X) scanf("%lld",&(X))
const ll mod = 1e9+7;
#define INFL 0x3f3f3f3f3f3f3f3fLL
 
//-------------------------<MATH>-------------------------------------------------------//
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll expo(ll base,ll pow){ll ans = 1;
   while(pow!=0){if(pow&1==1){ans = ans*base;ans = ans%mod;}
   base *= base;base%=mod;pow/=2;}return ans;}
ll inv(ll x){return expo(x,mod-2);}
ll mult_mod(ll a , ll b){a = a%mod; b = b%mod;
ll c = (a * b)%mod;
//cout << a << " " << b << endl;
return c;}
ll add_mod(ll a , ll b){a = (a + mod)%mod;b = (b + mod)%mod;ll c = (a + b)%mod;return c;}
ll fac[(int)(5e5 + 5)] , inv_fac[(int)(5e5 + 5)];
void precomp_factorial(int M){fac[0] = 1;for(int i = 1 ; i <= M ; i++) fac[i] = mult_mod(i , fac[i - 1]);
    inv_fac[M] = inv(fac[M]);for(int i = M - 1 ; i >= 0 ; i--) inv_fac[i] = mult_mod(i + 1 , inv_fac[i + 1]);}
ll nCk(ll n , ll k){ll ans = fac[n];ans = mult_mod(ans , inv_fac[n - k]);ans = mult_mod(ans , inv_fac[k]);return ans;}
int lo[(int)(1e3 + 6)];
void sieve(int M){for(int i = 2 ; i < M ; i++){ if(lo[i]) continue; for(int j = i ; j < M ; j += i)lo[j] = i;}}
int max_expo_prime_n_fac(ll N , int prime){int ress = 0;while(N){ress += (N/prime);N /= prime;}return ress;}
//-------------------------</MATH>-------------------------------------------------------//
 
//-------------------------<STRING>-------------------------------------------------------//
string get_prefix(string x , int MAX){return x.substr(0 , min((int)x.size() , MAX));}
string get_suffix(string x,int MAX){int dn=1;for(int i=x.size()-1;i>=0;i--){if(dn==MAX)return x.substr(i);dn++;}return x;}
string convert_to_binary(int x,int len) {string ans=""; while(x){if(x&1){ans='1'+ans;}
    else{ans ='0'+ans;}x/=2;}int k = ans.size();while(k < len){ans = '0' + ans;k++;}return ans;}
//-------------------------</STRING>-------------------------------------------------------//
 
ull llrand() {ull r = 0;for(int i = 0; i < 5; ++i){r = (r << 15)|(rand() & 0x7FFF);}return r & 0xFFFFFFFFFFFFFFFFULL;}
int dx[8] = {1 , 0 , -1 , 0 , 1 , -1 , -1 , 1};    // last 4 diagonal
int dy[8] = {0 , 1 , 0 , -1 , 1 , 1 , -1 , -1};
 
const int SZ = 2345678;

 int main(){
     
     int n;
     cin >> n;
     if(n >= 30) cout << "Yes" << endl;
     else cout << "No" << endl;
 }
