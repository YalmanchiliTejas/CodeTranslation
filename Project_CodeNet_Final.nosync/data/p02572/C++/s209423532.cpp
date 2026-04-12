/* kop Chy_Chy*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll , ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
#define si(x)   scanf("%d", &x)
#define sl(x)   scanf("%lld", &x)
#define pi(x)   printf("%d\n", x)
#define pl(x)   printf("%lld\n", x)
#define deb(x)  cout<< #x << " = " << x << endl // debugging kop 
#define mp      make_pair
#define pb      push_back
#define MOD     1000000007
#define PI      acos(-1)
#define ff      first
#define ss      second
#define newline printf("\n")
ll binpow(ll a, ll b); // binary exponentiation kop
void prime_factorization(ll n, vll &prime_factors); // prime factorization kop
ll gcd(ll a, ll b); // greatest common divisor kop. Use LONG LONG
void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}
void func(string s , string t){
    int a = s.size();
    int b = t.size();
    int m = (int)1e9;
    int cnt = 0;
    for(int i = 0; i <= a-b; i++){
        for(int j = 0; j < b; j++){
            if(s[j+i] != t[j]){
                cnt++;
            }
        }
        // cout<< cnt << "\n";
        m = min(cnt, m);
        cnt = 0;
    }
    cout<< m << "\n";
}
int main(){
    speedup();
    int t = 1;
    // cin>> t;
    while(t--){
        // khela final Mamooo
        int n; cin>> n;
        vll a(n);
        for(int i = 0; i < n; i++) cin>> a[i];
        vll sum(n);
        for(int i = n -2; i >= 0; i--){
            sum[i] = sum[i+1] + a[i+1];
            sum[i] %= MOD;
        }
        ll ans = 0;
        for(int i = 0; i < n-1; i++){
            ans += (sum[i] * a[i]) % MOD;
            ans %= MOD;
            
        }
        cout<< ans << "\n";
        
        
    }
    // kop kop return 
    return 0;
}


// kop kop functions:
ll binpow(ll a, ll b){
    a = a % MOD; ll res = 1;
    while(b > 0){
        if(b & 1) res *= a % MOD;
        a = a* a % MOD;b = b >> 1;}
    return res;
}
/*---------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
/*---------------------------------------------------------------------------------------------------------------*/
void prime_factorization(ll n, vll &prime_factors){
    // first two step taking care of composite number
    // taking care of 2
    while(n%2 == 0){
        prime_factors.pb(2);
        n = n / 2;
    }
    // now n must be odd. And the remaining prime divisors are odd. so we start from 3 and increamenting 2
    for(ll i = 3; i <= sqrt(n); i = i + 2){
        while(n%i == 0){
            prime_factors.pb(i);
            n = n / i;
        }
    }
    // now we are taking care of  n is prime number and greater than 2
    if(n > 2){
        prime_factors.pb(n);
    }
}
/*---------------------------------------------------------------------------------------------------------------*/













