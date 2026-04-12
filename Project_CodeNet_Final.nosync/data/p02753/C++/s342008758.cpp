#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include<limits.h>
#include<algorithm>
#include<queue>
#include<set>


#define MOD 1000000007

using namespace std;

long long int modpow(long long int a, long long int n) {
	if (n == 0)return 1;
	if (n == 1)return (a % MOD);

	long long int hanbun = n / 2;
	long long int amari = n % 2;

	long long int ans = (a * a) % MOD;
	ans = modpow(ans, hanbun);

	if (amari == 1)ans *= a;

	ans %= MOD;

	return ans;

}

long long int gcd(long long int a, long long int b) {
	if (a < b) {
		long long int tmp = a;
		a = b;
		b = tmp;
	}

	long long int amari = a % b;

	if (amari == 0)return b;

	return gcd(b, amari);
}

long long int lcm(long long int a, long long int b) {
	long long int ans = (a * b) % MOD;
	long long int wari = modpow(gcd(a, b), MOD - 2);
	ans = (ans * wari) % MOD;
	return ans;
}

long long int factElement[10000] = { 0 };

long long int factrial(int n) {

	if (factElement[n] != 0)return factElement[n];

	if (n == 0) {
		factElement[0] = 1;
		return factElement[n];
	}

	long long int ans = n * factrial(n - 1);
	factElement[n] = ans;
	return factElement[n];

}


int main()
{

	char a, b, c;
	cin >> a >> b >> c;

	if (a == b && b == c) {
		cout << "No" << endl;
		return 0;

	}

	cout << "Yes" << endl;

	return 0;

}

