#include <bits/stdc++.h>

#define fio() ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pi;
typedef pair<pi, ll> pii;

const ll mod = 1e9 + 7;
const ll maxn = 1e5 + 6;
const ll N = 1e2 + 2;
const ll inf = 1e12;
const ld eps = 1e-6;

ll n, cnt[maxn], deg[maxn];
vector <ll> adj[maxn];
bool mark[maxn];
vector <ll> q1, q2;
string ans = "Second";

void print() {
	for (auto i : q1)
		cout << i << " ";
	cout << endl;
}

int main() {
	fio();
	cin >> n;
	for (int i = 1; i < n; i++) {
		ll fr, to;
		cin >> fr >> to;
		fr--;
		to--;
		adj[fr].pb(to);
		adj[to].pb(fr);
		deg[fr]++;
		deg[to]++;	
	}
	for (int i = 0; i < n; i++) {
		if (deg[i] == 1)
			q1.pb(i);	
	}
	while (true) {
		for (int i = 0; i < q1.size(); i++) {
		//	cout << "1: " << q1[i] << endl;
			mark[q1[i]] = true;
			for (auto u : adj[q1[i]]) {
				if (!mark[u]) {
					cnt[u]++;
					q2.pb(u);	
				}
			}
		}
		q1.clear();
		for (int i = 0; i < q2.size(); i++) {
	//		cout << "2: " << q2[i] << endl;
			mark[q2[i]] = true;
			if (cnt[q2[i]] > 1) {
				cout << "First" << endl;
				return 0;	
			}
			for (auto u : adj[q2[i]]) {
				if (!mark[u]) {
					deg[u]--;
					if (deg[u] == 1) {
						q1.pb(u);	
					}
					if (deg[u] < 1) {
						cout << "First" << endl;
						return 0;	
					}
				}
			}
		}
		q2.clear();
		if (q1.empty())
			break;
	}
	cout << "Second" << endl;
}
