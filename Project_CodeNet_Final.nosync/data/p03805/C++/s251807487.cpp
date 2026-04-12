#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <fstream>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef complex<double> Point;

#define PI acos(-1.0)
#define EPS 1e-10
const ll INF = 1e9 + 7;
const ll MOD = 1e9 + 7;

#define FOR(i,a,b) for(long long i=(a);i<(b);i++)
#define REP(i,N) for(long long i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )
#define fi first
#define se second

int n, m;
int ans = 0;

int field[100][100];

void solve(int now, bool used[]){
	REP(i, n){
		if (!used[i])break;
		if (i == n - 1){
			ans++;
			return;
		}
	}

	REP(i, n){
		if (field[now][i] && !used[i]){
			used[i] = 1;
			solve(i, used);
			used[i] = 0;
		}
	}
}

int main(){
	cin >> n >> m;
	REP(i, m){
		int a, b;
		cin >> a >> b;
		a--; b--;
		field[a][b] = 1;
		field[b][a] = 1;
	}
	bool used[100] = {};
	used[0]=1;
	solve(0,used);
	cout << ans << endl;
}