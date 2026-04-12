#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <functional>
#include <utility>
#include <numeric>
#include <map>
using namespace std;


#define prec(i) cout << fixed << setprecision(i)

void outPut_YN(bool isYes) {
	if(isYes)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}

const long long MOD = 1000000007;

long long fact(long long k) {
	long long sum = 1;
	for (long long i = 2; i <= k; i++)
		sum *= i;

	return sum;
}

long long fact_mod(long long k) {
	long long sum = 1;
	for (long long i = 2; i <= k; i++)
		sum = (sum * i) % MOD;

	return sum;
}

int ctoi(char c) {
	if (c >= '0' && c <= '9')
		return c - '0';
	else
		return -1;
}

long long pow_mod(int a, int b) {
	long long ans = 1;
	for (int i = 0; i < b; i++)
		ans = (ans * a) % MOD;

	return ans;
}

long long powll(long long a, long long  b) {
	long long ans = 1;
	for (long long i = 0; i < b; i++)
		ans = ans * a;

	return ans;
}

long long modinv(long long a) {
	long long b = MOD, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= MOD;
	if (u < 0) u += MOD;
	return u;
}

vector<vector<int>> checkTree;
vector<int> turnTree;
vector<bool> isPassed;
int maxTurn;

int func(int pos, int turn) {
	cout << pos << endl;
	if (turn > maxTurn)
		return 0;

	if (checkTree[pos].size() > 0) {
		int max = 0;
		for (int i = 0; i < checkTree[pos].size(); i++) {
			if (!isPassed[checkTree[pos][i]]) {
				int t;
				if((t = func(checkTree[pos][i], turn + 1)) > max)
					max = t;
			}
		}
		isPassed[pos] = true;
		return max;
	}
	else {
		return turn;
	}
		
}


int main()
{
	long long n, m;

	cin >> n >> m;

	outPut_YN(n == m);

	return 0;
}