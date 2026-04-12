#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps = 1e-9;

// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt"


const int mod = 1000000007;
struct Mod {
public:
	int num;
	Mod() : Mod(0) { ; }
	Mod(long long int n) : num((n % mod + mod) % mod) {
		static_assert(mod < INT_MAX / 2, "mod is too big, please make num 'long long int' from 'int'");
	}
	Mod(int n) : Mod(static_cast<long long int>(n)) { ; }
	operator int() { return num; }
};

Mod operator+(const Mod a, const Mod b) { return Mod((a.num + b.num) % mod); }
Mod operator+(const long long int a, const Mod b) { return Mod(a) + b; }
Mod operator+(const Mod a, const long long int  b) { return b + a; }
Mod operator++(Mod &a) { return a + Mod(1); }
Mod operator-(const Mod a, const Mod b) { return Mod((mod + a.num - b.num) % mod); }
Mod operator-(const long long int a, const Mod b) { return Mod(a) - b; }
Mod operator--(Mod &a) { return a - Mod(1); }
Mod operator*(const Mod a, const Mod b) { return Mod(((long long)a.num * b.num) % mod); }
Mod operator*(const long long int a, const Mod b) { return Mod(a)*b; }
Mod operator*(const Mod a, const long long int b) { return Mod(b)*a; }
Mod operator*(const Mod a, const int b) { return Mod(b)*a; }
Mod operator+=(Mod &a, const Mod b) { return a = a + b; }
Mod operator+=(long long int &a, const Mod b) { return a = a + b; }
Mod operator-=(Mod &a, const Mod b) { return a = a - b; }
Mod operator-=(long long int &a, const Mod b) { return a = a - b; }
Mod operator*=(Mod &a, const Mod b) { return a = a * b; }
Mod operator*=(long long int &a, const Mod b) { return a = a * b; }
Mod operator*=(Mod& a, const long long int &b) { return a = a * b; }
Mod operator^(const Mod a, const int n) {
	if (n == 0) return Mod(1);
	Mod res = (a * a) ^ (n / 2);
	if (n % 2) res = res * a;
	return res;
}
Mod mod_pow(const Mod a, const int n) {
	if (n == 0) return Mod(1);
	Mod res = mod_pow((a * a), (n / 2));
	if (n % 2) res = res * a;
	return res;
}
Mod inv(const Mod a) { return a ^ (mod - 2); }
Mod operator/(const Mod a, const Mod b) {
	assert(b.num != 0);
	return a * inv(b);
}
Mod operator/(const long long int a, const Mod b) {
	assert(b.num != 0);
	return Mod(a) * inv(b);
}
Mod operator/=(Mod &a, const Mod b) {
	assert(b.num != 0);
	return a = a * inv(b);
}

#define MAX_MOD_N 1024000

Mod fact[MAX_MOD_N], factinv[MAX_MOD_N];
void init() {
	fact[0] = Mod(1); factinv[0] = 1;
	for (int i = 0; i < MAX_MOD_N - 1; ++i) {
		fact[i + 1] = fact[i] * Mod(i + 1);
		factinv[i + 1] = factinv[i] / Mod(i + 1);
	}
}
Mod comb(const int a, const int b) {
	return fact[a] * factinv[b] * factinv[a - b];
}

Mod tomod(const string st) {
	Mod ans = 0;
	for (int i = 0; i < st.size(); ++i) {
		ans = ans * 10 + Mod(st[i] - '0');
	}
	return ans;
}
Mod getzero(const string a, const string c) {
	Mod ans = 0;
	for (int i = 1; i <= a.size() - c.size(); ++i) {
		Mod up = tomod(a.substr(0, i));
		Mod down = tomod(a.substr(i + c.size(), a.size() - c.size() - i));

		Mod plus;
		if (a.substr(i, c.size())>c) {
			plus = (up)*mod_pow(10, a.size() - c.size() - i);
		}
		else if (a.substr(i, c.size()) == c) {
			plus = (up-Mod(1)) * mod_pow(10, a.size() - c.size() - i) + down + 1ll;
		}
		else {
			assert(false);
		}
		ans += plus;
	}
	return ans;
}
Mod getans(const string a, const string c) {
	if (c == "0")return getzero(a, c);
	Mod ans = 0;
	for (int i = 0; i <=a.size() - c.size(); ++i) {
		Mod up = tomod(a.substr(0, i));
		Mod down = tomod(a.substr(i + c.size(), a.size() - c.size() - i));

		Mod plus;
		if (a.substr(i, c.size())>c) {
			 plus= (up+1ll)*mod_pow(10, a.size() - c.size() - i);
		}
		else if (a.substr(i, c.size()) == c){
			plus = up * mod_pow(10, a.size() - c.size() - i) + down + 1ll;
		}
		else {
			plus = up*mod_pow(10, a.size() - c.size() - i);
		}
		ans += plus;
	}
	return ans;
}

Mod check(const string a, const string c) {
	Mod ans = 0;
	for (int i = 0; i <=a.size() - c.size(); ++i) {
		if (a.substr(i, c.size()) == c)ans+=1ll;
	}
	return ans;
}
int main() {
	string A, B, C; cin >> A >> B >> C;
	Mod aa = getans(A, C);
	Mod bb = getans(B, C);
	Mod ans = bb - aa + check(A, C);
	cout << ans << endl;
	return 0;
}