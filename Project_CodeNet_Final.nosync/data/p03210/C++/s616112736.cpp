#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int cl(int a, int b) {
	return (a - (a%b)) / b;//b=0だと積む
}
int up(int a, int b) {
	return cl(a + b - 1, b);//b=0だと積む
}
int ord(int a, int p) {
	if (a%p == 0) {
		return ord(a / p, p) + 1;
	}
	else {
		return 0;
	}
}
long long ruin(int a, int n, long long  p) {
	if (n == 0) {
		return (1 % p);
	}
	else {
		long long x = ruin(a, (n - (n % 2)) / 2, p);
		if (n % 2 == 0) {
			return (x*x) % p;
		}
		else {
			return (((x*x) % p)*a) % p;

		}

	}

}
long long com(int n, int r, int p) {
	if (r == 0) {
		return (1 % p);
	}
	else {
		long long x = com(n, r - 1, p);
		return (x*(n - r) / r) % p;
	}
}
long long sum(long long n, long long p) {
	if (n == 0) {
		return 0;
	}
	else {
		long long x = (n%p) + sum((n - (n%p)) / p, p);
		return x;
	}
}
int main()
{
	int x;
	cin >> x;
	if (x == 7 or x == 5 or x == 3) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}
