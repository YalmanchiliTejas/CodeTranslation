#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int mod = 1000 * 1000 * 1000 + 7;
int add(int a , int b)
{
	return a + b >= mod ? a + b - mod : a + b;
}
int sub(int a , int b)
{
	return a - b < 0 ? a - b + mod : a - b;
}
int mult(int a , int b)
{
	return a * (LL)b % mod;
}
const int MAX = 200005;
int fact[200005];
int inv[200005];
int invFact[200005];
int n , m , k;
int c(int n, int k)
{
	return mult(fact[n] , mult(invFact[k] , invFact[n - k]));
}
int main()
{
	int n , m , k;
	cin >> n >> m >> k;
    fact[0] = invFact[0] = fact[1] = invFact[1] = inv[0] = inv[1] = 1;
    
    for(int i = 2; i < MAX; i++)
    {
		fact[i] = mult(i , fact[i - 1]);
		inv[i] = mult(mod - (mod / i) , inv[mod % i]);
		
		invFact[i] = mult(invFact[i - 1] , inv[i]);
	}
	int ans = 0;
	int suma = 0;
    for(int i = 0; i < n; i++)
    {
		suma = add(suma , mult(i , m));
		ans = add(ans , mult(suma , m));
	}
	suma = 0;
	for(int i = 0; i < m; i++)
	{
		suma = add(suma , mult(n , i));
		ans = add(ans , mult(suma , n));
	}
	//cout << ans << " " << endl;
    cout << mult(ans , c(n * m - 2, k - 2));
    return 0;
}
