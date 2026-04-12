
#include <queue>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <map>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<ll> vint;
typedef vector<string> vstr;
typedef pair<ll, ll> pint;
unsigned long long inf = (1LL << 62);
ll mod = 1000000007;

//bool operator< (pint a, pint b) {
	//return a.second < b.second;

//}



ll gcd(ll a, ll b) {

	if (b == 0)
		return a;

	return gcd(b, a % b);


}

ll max(ll a, ll b) {
	if (a < b) {
		return b;
	}
	else
		return a;

}

ll min(ll a, ll b) {
	if (a < b)
		return a;

	return b;
}




pint dx[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

vector<pint> list;










void floyd(int N, ll** d) {

	rep(k, N+1){
		rep(i, N+1) {
			if (d[i+1][k+1] == inf) continue;
			rep(j, N+1) {
				if (d[j+1][k+1] == inf) continue;

				d[i+1][j+1] = min(d[i+1][j+1], d[i+1][k+1] + d[j+1][k+1]);

			}

		}
	}




}


ll vis[100005];
ll d[100005];
vector<ll> M[100005];
vector<ll> anslist;


stack<int> to_1;

ll col[100005];

void dfs(ll K, ll dist) {

	
	d[K] = dist;
	vis[K] = 1;

		
	for (int i = 0; i < M[K].size(); i++) {
		if (vis[M[K][i]] == 0) {
			
			dfs(M[K][i], dist + 1);
			
		}
	}

}



vector<unsigned long long> v;


vector<ll> e[10];


ll kotae;
void dfs3(ll K, ll length, ll m) {
	
	if (length == m) {

		kotae += 1;
	}


	for (int i = 0; i < e[K].size(); i++) {

		if (vis[e[K][i]] == 0) {
			vis[e[K][i]] = 1;
			dfs3(e[K][i], length + 1, m);
			vis[e[K][i]] = 0;
		}
	}

}



int main() {
	ll N, M;
	ll a, b;
	cin >> N >> M;


	rep(i, M) {
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}

	vis[1] = 1;

	dfs3(1, 1, N);

	
	cout << kotae << endl;

	return 0;
	
}