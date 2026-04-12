#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
#include<map>
#include<set>
#include<cstdlib>
#include<cmath>
#include<numeric>
#include<iomanip>
#include<functional>
#include<cstdlib>
#include<queue>
#include<deque>
#include <iterator>     // std::back_inserter
const double PI = acos(-1);
using namespace std;
using ll =long long;
#define rep(i,n)for(ll i=0;i<(n);i++)
const int mod = 998244353;
const ll inf = 1e18 + 1;
int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

ll gcd(ll a, ll b) {
	if (a % b == 0) {
		return b;
	}
	else {
		return gcd(b, a % b);
	}
}
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
};
//fixed << setprecision(2)
template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

/*コンビネーション*/

//ll f[101010], rf[101010];
//ll inv(ll x) {
//	ll res = 1;
//	ll k = mod - 2;
//	ll y = x;
//	while (k) {
//		if (k & 1) res = (res * y) % mod;
//		y = (y * y) % mod;
//		k /= 2;
//	}
//	return res;
//}
//void init() {
//	f[0] = 1;
//	for (ll i = 1; i < 101010;i++) f[i] = (f[i - 1] * i) % mod;
//	for(ll i = 0; i < 101010; i++) rf[i] = inv(f[i]);
//}
////---------------------------------------------------------------------------------------------------
//ll C(int n, int k) {
//	ll a = f[n]; // = n!
//	ll b = rf[n - k]; // = (n-k)!
//	ll c = rf[k]; // = k!
//
//	ll bc = (b * c) % mod;
//
//	return (a * bc) % mod;
//}

///*コンビネーション*/
//
///*Union Find*/
//#define MAX_N 200000
//#define MAX_M 200000
//vector<ll>par(MAX_N);
//vector<ll>ran(MAX_N);
//void init(ll N) {
//	rep(i, N) {
//		par[i] = i;
//		ran[i] = 0;
//	}
//}
//ll find(ll x) {
//	if (par[x] == x) {
//		return x;
//	}
//	else {
//		return par[x] = find(par[x]);
//	}
//}
////xとyの属する集合を併合
//void unite(ll x,ll y) {
//	x = find(x);
//	y = find(y);
//	if (x == y)return;
//	if (ran[x] < ran[y]) {
//		par[x] = y;
//
//	}
//	else {
//		par[y] = x;
//		if (ran[x] == ran[y])ran[x]++;
//	}
//}
//bool same(ll x, ll y) {
//	return find(x) == find(y);
//}
///*Union Find*/
//小文字=大文字+32
//struct edge {
//	vector<int>to;
//	ll cost;
//	int p;
//	ll w;
//	int col;
//};
//	int N;
//	cin >> N;
//	vector<pair<int, pair<int,ll>>>Q(N-1);
//	vector<ll> w(N - 1);
//	rep(i, N-1){
//		cin >> Q[i].first>>Q[i].second.first>>Q[i].second.second;
//	}
//	sort(Q.begin(), Q.end());
//	vector<edge>G(N);
//	rep(i, N - 1) {
//		G[Q[i].first-1].to.push_back(Q[i].second.first-1);
//		G[Q[i].second.first-1].to.push_back(Q[i].first-1);
//		G[Q[i].second.first - 1].p = Q[i].first-1;
//		G[Q[i].second.first-1].w = Q[i].second.second;
//	}
//	G[0].cost = 0;
//	G[0].p = -1;
//	G[0].w = 0;
//	queue<int>Qu;
//	vector<bool> A(N,true);
//	for (int i = 0; i < G[0].to.size(); i++) {
//		Qu.push(G[0].to[i]);
//		A[G[0].to[i]] = false;
//	}
//	int v;
//	while (!Qu.empty()) {
//		v = Qu.front();
//		Qu.pop();
//		G[v].cost = G[G[v].p].cost + G[v].w;
//		for (int i = 0; i < G[v].to.size(); i++) {
//			if (A[G[v].to[i]]) {
//				Qu.push(G[v].to[i]);
//				A[G[v].to[i]] = false;
//			}
//		}
//	}
//	G[0].col = 0;
//	vector<bool>B(N, true);
//	for (int i = 0; i < G[0].to.size(); i++) {
//		Qu.push(G[0].to[i]);
//			cout << G[0].to[i]<<endl;
//			B[G[0].to[i]] = false;
//	}
//	while (!Qu.empty()) {
//		v = Qu.front();
//		Qu.pop();
//		if (labs(G[v].cost-G[G[v].p].cost) % 2 == 0) {
//			if (G[G[v].p].col == 0) {
//				G[v].col = 0;
//			}
//			else {
//				G[v].col = 1;
//			}
//		}
//		else {
//			if (G[G[v].p].col == 0) {
//				G[v].col = 1;
//			}
//			else {
//				G[v].col = 0;
//			}
//		}
//		for (int i = 0; i < G[v].to.size(); i++) {
//			if (B[G[v].to[i]]) {
//				Qu.push(G[v].to[i]);
//				B[G[v].to[i]] = false;
//			}
//		}
//	}
//	rep(i, N) {
//		//cout << G[i].col << endl;
//	}
//
//}
ll func(ll X, ll M) {
	return X % M;
}
struct num {
	ll sum;
	ll cnt=-1;
};
int main() {
	ll N,X,M;
	cin >> N>>X>>M;
	vector<num>ch(M);

	ll cnt = 0;
	ll a = X;
	ll sum=X;
	ll p;
	cnt++;
	ch[a].cnt = cnt;
	ch[a].sum = 0;
	while(cnt!=N) {
		p = a;
		a = func(a*a,M);
		if (ch[a].cnt != -1) {
			break;
		}
		ch[a].sum=sum;
		sum += a;
		cnt++;
		ch[a].cnt=cnt;
	}
		
	if (cnt != N) {
		sum += ((N-ch[a].cnt+1) / (1+ch[p].cnt-ch[a].cnt)-1)*(sum-ch[a].sum);
		cnt = cnt+((N - ch[a].cnt+1) / (1 + ch[p].cnt - ch[a].cnt)-1)*(1 + ch[p].cnt - ch[a].cnt);
		
		if (cnt == N) {
			cout << sum;
			return 0;
		}
		sum += a;
		cnt++;
		while (cnt != N) {
			a = func(a*a, M);
			sum += a;
			cnt++;
		}
	}
	cout << sum;
	

}
