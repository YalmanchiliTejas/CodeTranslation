#include<bits/stdc++.h>
#define for_int(i,a,b) for(int i=(a);i<=(b);++i)
#define rep_int(i,a,b) for(int i=(a);i>=(b);--i)
#define for_ll(i,a,b) for(ll i=(a);i<=(b);++i)
#define rep_ll(i,a,b) for(ll i=(a);i>=(b);--i)
#define ull unsigned long long
#define ll long long
#define db double
#define HPMAX 1005
#define KMP_MAX 1005
#define prime_MAX 1e6+5
#define quick_pow_mod 1e9+7
#define PII pair<int,int>
const int factor_N = 1e7 + 5;
const int tree_arr_N = 1e6 + 5;
using namespace std;
//快读
int read() {
	char c = getchar();
	int x = 0, f = 1;
	for (; !isdigit(c); c = getchar())
		if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	return x * f;
}
int x;
int main() {
	x = read();
	if (x >= 30) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}