#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <numeric>
#include <queue>
#include <numeric>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <map>
#include <functional>
#include <limits>
#include <set>
#include <stack>
#include <cctype>
#include <fstream>
#define rep(i,a,b) for((i)=a;i<(int)(b);i++)

#define AAA (1000000007) 


using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pairII;
typedef vector<int> vecI;

ll gcd(ll a, ll b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
ll powD(ll a, ll b) {
	ll ans = 1;
	a %= AAA;
	for (int i = 0; i < b; i++)
	{
		ans *= a;
		ans %= AAA;
	}
	return ans;
}

int main() {
	int i, j, k;
	int N, M, K;
	const ll AAA2 = AAA * 2;
	cin >> N;
	vector<ll> A(N);
	vector<ll> B(N);
	ll sum = 0;
	ll a2sum = 0;
	rep(i, 0, N) {
		cin >> A[i];
		sum += A[i];
		B[i] = A[i] * A[i] % AAA2;
		a2sum += B[i];
	}
	sum %= AAA2;
	a2sum %= AAA2;
	ll sum2 = sum * sum % AAA2;

	ll ans = (sum2 - a2sum + AAA2) % AAA2 / 2;
	cout << ans;
	return 0;

}
