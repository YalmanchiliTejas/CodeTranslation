#include <iostream> 
#define ll long long 
using namespace std;
const int MOD = 1e9 + 7;

ll power(ll x, ll y){
    x %= MOD;
    ll ans = 1;
    while(y){
        if(y & 1)
            ans = (ans * x) % MOD;
        y >>= 1LL;
        x = (x * x) % MOD;
    }
    return ans;
}

ll ad(ll a, ll b){
    return((a % MOD + b % MOD) % MOD);
}
ll sub(ll a, ll b){
    return((a % MOD - b % MOD + MOD) % MOD);
}
ll mul(ll a, ll b){
    return(((a % MOD) * (b % MOD)) % MOD);
}
ll divi(ll a, ll b){
    return(mul(a, power(b, MOD - 2)) % MOD);
}

int findProductSum(ll A[], ll n) 
{ 
    ll array_sum = 0; 
    for (int i = 0; i < n; i++) 
        array_sum = ad(array_sum, A[i]); 
    ll array_sum_square = mul(array_sum, array_sum);
    ll individual_square_sum = 0; 
    for (int i = 0; i < n; i++)
        individual_square_sum = ad(individual_square_sum, mul(A[i],A[i]));
    return divi(sub(array_sum_square, individual_square_sum),2); 
} 

int main() 
{ 
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; ++i)
    	cin >> a[i];
    cout << findProductSum(a, n); 
    return 0; 
} 