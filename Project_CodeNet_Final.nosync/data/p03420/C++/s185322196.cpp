#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;
#define int long long
#define endl '\n'
typedef long long ll;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin >> n >> k;
	int res = 0;
	for(int b = k+1; b <= n; ++b) {
		int maxMult = (n-k)/b;
		res += (b-k) * maxMult + min(n,(maxMult+1)*b-1) - (maxMult*b+k) + 1;
		if(k == 0) --res;
	}
	cout << res;
}
