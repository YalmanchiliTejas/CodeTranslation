#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;

const int maxN = 1e5 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

ll gcd(ll a, ll b){return !b ? a : gcd(b, a % b);}
ll modP(ll a, ll b) {return (!b ? 1 : (modP(a, b / 2) * modP(a, b / 2) * (b % 2 ? a : 1)) % MOD);}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, a, x, cnt;
	cin >> n;
	x = 0;
	cnt = 0;
	for (int i = 0; i < n; i++){
		cin >> a;
		if (a >= x){
			cnt += 1;
			x = a;
		}
	}
	cout << cnt << endl;
	return 0;
}

