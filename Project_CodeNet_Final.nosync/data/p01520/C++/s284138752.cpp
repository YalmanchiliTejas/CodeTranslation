#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define EPS 1e-10
#define INF 1000000
#define mp make_pair
#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long ll;

int main() {
	int N, T, E;
	cin >> N >> T >> E;
	int x[N];
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}
	int ans = -1;
	for (int i = 0; i < N; i++) {
		int diff = T % x[i];
		if (T+diff-x[i] >= T-E || T+diff <= T+E) {
			ans = i+1;
			break;
		}
	}
	cout << ans << endl;
}