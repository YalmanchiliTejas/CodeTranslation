#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <numeric>
#include <cmath>

#define FOR(i, f, n) for(int (i) = (f); (i) < (n); (i)++)
#define RFOR(i, f, n) for(int (i) = (f); (i) >= (n); (i)--)
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define rrep(i, n) for(int (i) = (n); (i) >= 0; (i)--)
#define step(i, f, n, a) for(int (i) = (f); (i) < (n); (i)+=a)
#define rstep(i, f, n, a) for(int (i) = (f); (i) >= (n); (i)-=a)
#define p(...) printf(__VA_ARGS__); cout << endl;
#define gets(x) x; cin >> x;
#define puts(x) x; cout << x << endl;
#define list_input(x, n) x[(n)]; for(int (i) = 0; (i) < (n); (i)++) cin >> x[i];
#define lambda(a, b, c) [](const a, const b){ return c ;}
#define key(t, x, compare) [](const t& a, const t& b){ return a x compare b x ;}

using namespace std;

using ll = long long;
using pii = pair<int, int>;
const int nmax = 8;
bool graph[nmax][nmax]; //パスを格納

int dfs(int v, int n, bool already[nmax]){
	bool ok = true; //全部通ったか

	rep(i, n){
		if (already[i]==false){
			ok = false;
		}
	}

	if (ok){
		return 1;
	}

	int ret = 0;
	rep(i, n){
		if (graph[v][i] == false){
			continue;
		}
		if (already[i]){
			continue;
		}
		already[i] = true; //通った
		ret += dfs(i, n, already);
		already[i] = false;
	}
	return ret;
}

int main(){
	int n, m, a, b;
	cin >> n >> m;
	rep(i, m){
		cin >> a >> b;
		graph[a-1][b-1] = graph[b-1][a-1] = true;
	}
	bool already[nmax];
	rep(i,n){
		already[i] = false;
	}

	already[0] = true; //初期地点は通ったことにする
	puts(dfs(0, n, already))
}
