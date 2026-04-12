#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define FOR(i, n) for(int i = 0; i < (int) n; i++)
#define all(v) v.begin(), v.end()
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int MOD = 1e9+7;
const int INF = 1e9+7;

int n;
ll memo[3000][3000];
ll v[3000];

ll f(int a, int b){
	if(memo[a][b] != -1){
		return memo[a][b];
	}
	if(a == b){
		memo[a][b] = v[a];
		return v[a];
	}
	if(a+1 == b){
		memo[a][b] = max(v[a], v[b]);
		return memo[a][b];
	}

	memo[a][b] = max(min(f(a+2, b), f(a+1, b-1)) + v[a],
		         min(f(a, b-2), f(a+1, b-1)) + v[b]);
	return memo[a][b];
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);

	memset(memo, -1, sizeof(memo));

	cin >> n;
	ll sum = 0;
	FOR(i, n){
		cin >> v[i];
		sum += v[i];
	}

	cout << 2*f(0, n-1) - sum << '\n';

	return 0;
}