#include<bits/stdc++.h>
using namespace std;

string s;
int N, K;

long long com(long long n, long long r) {
	if(r < 0 || r > n) return 0;
	else if(r == 1) return n;
	else if(r == 2) return n * (n-1) / 2;
	else return n * (n-1) * (n-2) / 6;
}

long long mypow(long long n, long long k) {
	long long res = 1;
	for(int i = 0; i < k; i++) res *= n;
	return res;
}

long long solve(int i, int k, bool smaller) {
	if(i == N) {
		if(k == 0) return 1;
		else return 0;
	}

	if(k == 0) return 1;

	if(smaller) return com(N-i, k) * mypow(9, k);
	else {
		if(s[i] == '0') return solve(i+1, k, false);
		else {
			long long zero = solve(i+1, k, true);
			long long aida = solve(i+1, k-1, true) * (s[i] - '1');
			long long icchi = solve(i+1, k-1, false);
			return zero + aida + icchi;
		}
	}
}

int main() {
	cin >> s >> K;
	N = s.size();
	cout << solve(0, K, false) << endl;
	return 0;
}
