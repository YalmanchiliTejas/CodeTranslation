#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int,int> PP;

/*
    freopen("input","r",stdin);
    freopen("output","w",stdout);
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll N, K;
    cin >> N >> K;
    ll sol = 0;
    for (ll i = K + 1;i <= N;i++) {
    	ll r = N / i;
    	ll q = N % i;
    	if (q == 0) {
    		sol += r * (i - K);
    	}
    	else {
    		r--;
	    	sol += (i - K) * (r + 1);
	    	if (K == 0) q--;
	    	sol += max(0LL, q - K + 1);
	    }
    }
    cout << sol << endl;
    return 0;
}