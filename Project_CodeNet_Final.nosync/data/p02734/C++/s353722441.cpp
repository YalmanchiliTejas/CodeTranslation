#include <cstdio>
#include <algorithm>  
#include <bitset>
#include <cassert>
#include <ctime>  
#include <cmath>  
#include <cstdlib>  
#include <cstring>  
#include <functional>  
#include <iostream>  
#include <deque>  
#include <stack>
#include <queue>  
#include <vector>  
#include <map>  
#include <set>  
#include <string>  
#include <unordered_map>  
#include <unordered_set>  
#pragma warning(disable:4996)

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, int> pdi;

const int INF = 1e9;
const int MAXN = 3e3 + 5;
const ll MOD = 998244353;

ll N, S, A[MAXN], ans;
ll D[MAXN][MAXN];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> S;
	for(int i=1; i<=N; i++) cin >> A[i];

	for(int i=1; i<=N; i++) {
		D[i-1][0] = i;
		for(int w=1; w<=S; w++) {
			if(w >= A[i]) D[i][w] = (D[i-1][w] + D[i-1][w-A[i]]) % MOD;
			else D[i][w] = D[i-1][w];
		}
		ans = (ans + D[i][S]) % MOD;
	}
	cout << ans;
}