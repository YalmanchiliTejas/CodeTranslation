#include <cmath>
#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>
#include <numeric>
#include <map>   
#include <stdio.h>

#define FOR(i,a,b) for(i=(a);i<(b);++i) 
#define FORR(i,a,b) for(i=(a);i>(b);--i)
#define REP(i,n) for(i=0;i<(n);++i)
#define REPR(i,n) for(i=(n);i>0;--i)
#define PB push_back
#define ull unsigned long long
#define ll long long
#define INT_MAX 2147483647
#define LL_MAX 9223372036854775807
#define sortR(a,b) sort(a, b, greater<int>())

using namespace std;

int main() {
	int N, K, i, one_saisyo, one_saigo, zero_saisyo, zero_saigo, before;
	string S;
	vector<pair<int, int>> zero, one;
	cin >> N >> S >> K;
	char s = S[K-1];
	REP(i, N) {
		if (S[i] == s)
			cout << s;
		else
			cout << "*";
	}
	cout << endl;
	return 0;
}

