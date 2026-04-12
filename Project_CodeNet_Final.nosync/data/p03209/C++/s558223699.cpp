#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define For(i, a, b)	for(int i = (a); i < (b); ++i)
#define rep(i, n)		For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;

long long rec(int n, long long x) {
	// n-1 次元バーガーのサイズとそこに含まれるパティの数を知る
	if(n == 0) return 1;
	long long len = (1LL << (n+1)) - 3;
	long long num = (1LL << n) - 1;
	if(x == 1) return 0;
	else if(x <= len + 1) return rec(n-1, x-1);
	else if(x == len + 2) return num + 1;
	else if(x <= (len + 1) * 2 + 1) return num + 1 + rec(n-1,x-len-2);
	else return num * 2 + 1; //は？
}
int main(){
	int n;
	cin >> n;
	ll x;
	cin >> x;
	cout << rec(n, x) << endl;
}
