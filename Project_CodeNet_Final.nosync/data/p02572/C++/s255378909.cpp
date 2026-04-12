#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<sstream>
#include<iterator>
#include<list>

using namespace std;

typedef  long long int lint;

#define rep(i, n) for (lint i = 0; i < n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define upper(v,hoge) upper_bound(v.begin(),v.end(),hoge)
#define lower(v,hoge) lower_bound(v.begin(),v.end(),hoge)
#define mp make_pair
#define enld endl

lint power(lint x, lint n, lint m) {
	//(x^n)%mを返す
	lint res = 1;
	x %= m;
	while (n > 0) {
		if (n % 2 == 1) {
			res = res * x % m;
		}
		x = x * x % m;
		n /= 2;
	}
	return res;
}

lint invmod(lint n, lint m) {
	//nの逆元を返す
	lint ret = 0;
	ret = power(n, m - 2, m);
	return ret;
}

lint comb(lint n, lint k, lint m) {
	//nCk%MODを返す
	//O(k)
	lint ans = 1;
	rep(i, k) {
		ans *= n - i;
		ans %= m;
		ans *= invmod(k - i, m);
		ans %= m;
	}
	return ans;
}

int main() {
	lint MOD = pow(10, 9) + 7;
	lint N;
	cin >> N;
	vector<lint>A(N);
	rep(i, N) {
		cin >> A[i];
	}
	lint sum = 0;
	lint sig = 0;
	rep(i, N) {
		sum += A[i];
		sum %= MOD;
	}
	rep(i, N) {
		sig += A[i] * A[i];
		sig %= MOD;
	}
	lint ans = sum * sum - sig + MOD;
	ans %= MOD;
	ans *= invmod(2, MOD);
	ans %= MOD;
	cout << ans << endl;
}