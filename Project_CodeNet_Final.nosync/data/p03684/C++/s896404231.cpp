#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int, pii> para;
const int inf = 1e9 + 7;
const int maxN = 1e6 + 5;

int n, a, b, parent[maxN], ranka[maxN];
vector<pii> wek1, wek2;
vector<para> edges;


int find(int x) {
	if (parent[x] == 0)
		return x;
	parent[x] = find(parent[x]);
	return parent[x];
}

void unionX(int x, int y) {
	int xroot = find(x);
	int yroot = find(y);
	if (ranka[xroot] > ranka[yroot]) {
		parent[yroot] = xroot;
	} else {
		parent[xroot] = yroot;
		if (ranka[xroot] == ranka[yroot])
			ranka[yroot]++;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin>>n;
	REP(i, n) {
		cin>>a>>b;
		wek1.pb(pii(a, i + 1));
		wek2.pb(pii(b, i + 1));
		parent[i + 1] = 0;
		ranka[i + 1] = 0;
	}
	sort(wek1.begin(), wek1.end());
	sort(wek2.begin(), wek2.end());

	RI(i, n - 1) {
		int cost = wek1[i].st - wek1[i - 1].st;
		edges.pb(para(cost, pii(wek1[i].nd, wek1[i - 1].nd)));
		cost = wek2[i].st - wek2[i - 1].st;
		edges.pb(para(cost, pii(wek2[i].nd, wek2[i - 1].nd)));
	}
	sort(edges.begin(), edges.end());
	ll total = 0;
	for (auto p : edges) {
		a = p.nd.st;
		b = p.nd.nd;
		if (find(a) != find(b)) {
			total += p.st;
			unionX(a, b);
		}
	}
	cout<<total;
	return 0;
}
