#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <math.h>
#include <cmath>
#include<complex>
#include<cctype>
#include<string>
#include<set>
#include<iomanip>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include<bitset>
#include <deque>
#include <climits>
#include <typeinfo>
#include <utility> 
#include <numeric>
using namespace std;
using Complex = complex<double>;
using ll = long long;
template<typename T>using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const ll inf = 1145141919810364364LL;
double PI = acos(-1.0);
#define all(x) (x).begin(),(x).end()
#define puts(x) cout << x << endl
#define rep(i,m,n) for(ll i = m;i < n;++i)
#define pb push_back
#define fore(i,a) for(auto &i:a)
#define rrep(i,m,n) for(ll i = m;i >= n;--i)

vector<int>E[101010];
int used[101010];
int N;

int ok = 1;
void dfs(int now, int p) {
	int cnt = 0;
	fore(x, E[now]) {
		if (x != p){
			dfs(x,now);
			cnt += 1 - used[x];
		}
	}
	if (cnt == 0)return;
	else if (cnt == 1) { used[now] = 1; return; }
	else ok = 0;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N-1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		E[a].pb(b);
		E[b].pb(a);
	}

	dfs(0,-1);

	if (!ok)puts("First");
	else if (used[0] == 0)puts("First");
	else puts("Second");


	return 0;
}