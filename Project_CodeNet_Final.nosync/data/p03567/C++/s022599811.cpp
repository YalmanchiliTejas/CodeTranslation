#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#include<iomanip>
#define int long long
#define ll getchar();getchar();return 0;
using namespace std;
bool prime(int n) {
	int cnt = 0;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n%i == 0)cnt++;
	}
	if (cnt != 1)return false;
	else return n != 1;
}
int gcd(int x, int y) {
	int ans;
	for (int i = (min(x, y)); i >= 1; i--) {
		if (x%i == 0 && y%i == 0) {
			ans = i;
			break;
		}
	}
	return ans;
}
int yakusuunowa(int n) {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (n%i == 0)ans += i;
	}
	return ans;
}
int lcm(int x, int y) {
	return x * y / gcd(x, y);
}
int ketanowa(int n) {
	int cnt = 0, sum = 0;
	for (int i = 10; i <= n * 10; i *= 10) {
		if (i == 10)cnt += n % i;
		else sum += (n%i - n % (i / 10)) / (i / 10);
	}
	return cnt + sum;
}
signed main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] == 'A'&&s[i+1] == 'C') {
			puts("Yes");
			getchar(); getchar(); return 0;
		}
	}
	puts("No");
	ll
}