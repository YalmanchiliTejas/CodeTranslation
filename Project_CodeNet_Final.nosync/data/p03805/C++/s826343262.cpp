#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
#include <utility>
#include <numeric>
#include <string>
#include <set>
#include <map>
#include <tuple>
#include <queue>
#include <stack>
#include <deque>
#define rep(i, a, n) for(int (i) = (int)(a);(i) < (int)(n);++(i))
#define repe(i, a, n) for(int (i) = (int)(a);(i) <= (int)(n);++(i))
#define repif(i, a, x) for(int (i) = (int)(a);(x);++(i))
#define repr(i, a, n) for(int (i) = (int)(a);(i) > (int)(n);--(i))
#define reper(i, a, n) for(int (i) = (int)(a);(i) >= (int)(n);--(i))
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define RNG(x, n) &((x)[0]), &((x)[n])
#define BRK(x) { (x); break; }
#define ADD(a, b) ((((a)%MOD)+((b)%MOD))%MOD)
#define MUL(a, b) ((((a)%MOD)*((b)%MOD))%MOD)
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define yes cout << "yes" << endl;
#define no cout << "no" << endl;
#define fcout cout << fixed << setprecision(10)
#define pb push_back
#define pf push_front
#define mt make_tuple
#define fi first
#define se second
#define EPS (1e-20)
#define INF 2147483647
#define MOD 1000000007
using llint = long long;
using VI = std::vector<int>;
using PII = std::pair<int, int>;
using SI = std::set<int>;
using MII = std::map<int, int>;
using TIII = std::tuple<int, int, int>;
using VLL = std::vector<llint>;
using MCI = std::map<char, int>;
using namespace std;



int N, M;
bool g[10][10];


bool judge(VI& perm){
	rep(i, 0, N-1)
		if(!g[perm[i]][perm[i+1]]) return false;
	return true;
}


int solve(){
	int ans = 0;
	VI perm = VI(N);
	iota(ALL(perm), 0);
	do {
		if(judge(perm)) ans++;
	} while(next_permutation(perm.begin()+1, perm.end()));
	return ans;
}


signed main(){
	cin >> N >> M;
	rep(i, 0, M){
		int a, b;
		cin >> a >> b, a--, b--;
		g[a][b] = g[b][a] = true;
	}

	cout << solve() << endl;

	return 0;
}