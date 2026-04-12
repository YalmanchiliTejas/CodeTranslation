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

int main(){
    speedup();
    int t = 1;
    // cin>> t;
    while(t--){
        // khela final Mamooo
        int x; cin>> x;
        if(x >= 30) cout<< "Yes\n";
        else cout<< "No\n";
        
        
        
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












