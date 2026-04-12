#include <iostream>
#include <ccomplex>
#include <vector>
#include <cassert>
#include <utility>
#include <algorithm>
#include <string>
#include <deque>
#include <queue>
#include <functional>
#include <cmath>
#include <iomanip>
#include <map>
#include <numeric>
#include <list>
#include <assert.h>
#include <math.h>
#include <valarray>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <complex>
#include <list>
#include <time.h>
#include <stack>
#include <locale>
#include <clocale>
#include <ctype.h>
#include <wchar.h>
#include <random>
#include <vector>

using namespace std;
typedef long long int LL;
typedef long long int ll;
typedef pair<long long int, long long int> pii;
typedef pair<double, double> pdd;

#define SORT(c) sort((c).begin(),(c).end())
#define BACKSORT(c) sort((c).begin(),(c).end(),std::greater<LL>())
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

LL  solve(LL i,LL N,LL K) {
	LL sum = 0;
	if ((N / i)*(i - K) > 0) 
	{
		sum += (N / i)*(i - K);
	}

	if (K == 0) {
		sum += N % i;
	}
	else {
		if (N%i - (K - 1) > 0)
		{
			sum += N % i - (K - 1);
		}
	}
	return sum;
}

int main() {
	LL N, K;
	cin >> N >> K;

	LL sum = 0;
	FOR(i, 1, N + 1) {
		sum += solve(i, N,K);
	}

	cout << sum << endl;
}