#if _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#ifndef ONLINE_JUDGE 
const bool DEBUG = true;
#else
const bool DEBUG = false;
#endif

// Reads a 1D vector
template <class T>
void read1d(vector<T> & arg) {
	const int l = arg.size();
	for (int i = 0; i < l; ++i) cin >> arg[i];
}

void read() {}
// Reads arbitrary values
template <class T1, class... T2>
void read(T1& var1, T2&... var2) { cin >> var1; read(var2...); }



void pln() { cout << (DEBUG ? "]\n" : "\n"); }
template <class T1, class... T2>
void pln(const T1& var1, const T2& ... var2) { cout << var1 << " "; pln(var2...); }

// Prints arbitrary values and goes to next line
template <class T1, class... T2>
constexpr void print(const T1& var1, const T2& ... var2) { cout << (DEBUG ? " [ " : ""); pln(var1, var2...); }

// Prints arbitrary values and goes to next line ONLY IF IN DEBUG MODE
template <class T1, class... T2>
constexpr void debug(const T1& var1, const T2& ... var2) { if (!DEBUG) return;  cout << " debug : [ "; pln(var1, var2...); }





using ll = long long;
using ull = unsigned long long;


#define all(x) begin(x), end(x)

const bool MULTIPLE_TEST_CASES = 0;
const ll mod = 1e9 + 7;


void exec() 
{
	int n;
	cin >> n;

	ll sum = 0;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];
	for (int i : arr) {
		sum += ll(i);
		sum %= mod;
	}

	ll ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		sum -= arr[i];
		sum = (sum + mod) % mod;

		ans += (arr[i] * sum) % mod;
		ans %= mod;
	}

	print(ans);
}

















int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	if (!MULTIPLE_TEST_CASES)
		exec();
	else {
		int n;
		cin >> n;

		while (n--)
			exec();
	}

    return 0;
}