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
#define ll long long
#define INT_MAX 2147483647
#define LL_MAX 9223372036854775807
#define sortR(a,b) sort(a, b, greater<int>())

using namespace std;

long long GCD(long long a, long long b) {
	if (a < b)
		swap(a, b);
	if (b == 0) return a;
	else return GCD(b, a % b);
}
bool sosuu_check(int num) {
	int i;
	for (i = 2; i <= sqrt(num); ++i) {
		if (num%i == 0)
			return false;
	}
	return (num < 2) ? false : true;
}



int main() {
	ll N;
	cin >> N;
	if (N == 7 || N == 5 || N == 3)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}