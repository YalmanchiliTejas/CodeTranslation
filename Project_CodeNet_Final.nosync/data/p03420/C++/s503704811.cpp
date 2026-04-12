#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <limits>
#include <random>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define RREP(i,n) for(int (i)=(int)(n)-1;i>=0;i--)
#define REMOVE(Itr,n) (Itr).erase(remove((Itr).begin(),(Itr).end(),n),(Itr).end())
typedef long long ll;

int main() {

	ll N,K;
	cin >> N >> K;

	if (K == 0) {
		cout << N * N << endl;
		return 0;
	}

	ll ans = 0;
	for (ll b = 2; b <= N; b++) {
		if (K > b - 1) continue;
		ll itr = N / b;
		ans += itr * (b - 1 - (K - 1));
		ll left_b = N % b;
		ans += max(0LL, left_b - (K - 1));
	}

	cout << ans << endl;

	return 0;
}