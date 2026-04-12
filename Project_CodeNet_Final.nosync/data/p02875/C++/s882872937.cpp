#include <bits/stdc++.h>

using namespace std;

long long mod = 998244353ll;


long long modInverse(long long a, long long m)
{
    long long m0 = m;
    long long y = 0, x = 1;

    if (m == 1)
      return 0;

    while (a > 1)
    {
        // q is quotient
        long long q = a / m;
        long long t = m;

        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
       x += m0;

    return x;
}


int main(){
	int n;
	cin >> n;
	
	long long ans = 1;
	for(int i = 0;i < n;i++){
		ans *= 3;
		ans %= mod;
	}
	
	long long v = 1;
	for(int i = n;i > n/2;i--){
		ans -= 2 * v;
		
		v *= 2;
		v *= i;
		v %= mod;
		v *= modInverse(n-i+1,mod);
		v %= mod;
	}
	ans += mod*mod;
	ans %= mod;
	cout << ans;
}
