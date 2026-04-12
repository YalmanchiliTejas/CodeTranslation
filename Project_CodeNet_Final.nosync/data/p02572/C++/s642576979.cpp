#include <iostream> 
using namespace std; 
typedef long long int ll;
const ll mod = 1e9 + 7;

ll mul_inv(ll a, ll b = mod) {
	ll t1 = a, t2 = b, t3;
	ll v1 = 1, v2 = 0, v3;
	while (t2 != 1) {
		ll x = t1 / t2;
		t3 = t1 - x*t2;
		v3 = v1 - x*v2;
		t1 = t2, t2 = t3;
		v1 = v2, v2 = v3;
	}
	return (v2 + b) % b;
}
// required function 
ll findProductSum(ll A[], int n) 
{ 
    // calculating array sum (a1 + a2  ... + an) 
    ll array_sum = 0; 
    for (int i = 0; i < n; i++) 
        array_sum = (array_sum + A[i]) % mod; 
  
    // calcualting square of array sum 
    // (a1 + a2 + ... + an)^2 
    ll array_sum_square = (array_sum * array_sum) % mod; 
    
  
    // calcualting a1^2 + a2^2 + ... + an^2 
    ll individual_square_sum = 0; 
    for (int i = 0; i < n; i++) 
        individual_square_sum = (individual_square_sum + A[i]*A[i]) % mod; 
  
    // required sum is (array_sum_square - 
    // individual_square_sum) / 2 
    ll ans = 0;
    if(array_sum_square - individual_square_sum < 0) ans = array_sum_square - individual_square_sum + mod; 
    else ans = array_sum_square - individual_square_sum;
    ans = ans * mul_inv(2ll,mod);
    ans %=mod;
    if(ans < 0) ans += mod;
    return ans;
} 
  
// Driver code 
int main() 
{ 
	int n;
	cin >> n;
    ll A[n];
    for(int i = 0; i <n; i++) cin >> A[i];
    cout << (findProductSum(A,n));
    return 0; 
} 