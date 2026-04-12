#include<iostream>
#include<iomanip>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<tuple>
#include<complex>
#define REP(i, N) for(ll i = 0; i < N; ++i)
#define FOR(i, a, b) for(ll i = a; i < b; ++i)
#define ALL(a) (a).begin(),(a).end()
#define pb push_back
#define INF (long long)1000000000
#define MOD 1000000007
#define EPS (long double) 1e-8
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
int dh[4] = {1, 0, -1, 0};
int dw[4] = {0, 1, 0, -1};

using namespace std;

int main() {
	ll n;
	cin>>n;
	vector<P> p(n);
	REP(i, n) cin>>p[i].first>>p[i].second;
	vector<bool> used(n, false);
	set<P> x;
	set<P> y;
	REP(i, n) {
		P xi, yi;
		xi.first = p[i].first;
		xi.second = i;
		yi.first = p[i].second;
		yi.second = i;
		x.insert(xi);
		y.insert(yi);
	}
	ll res = 0;
	priority_queue<P, vector<P>, greater<P> > q;
	used[0] = true;
	set<P>::iterator itex = x.find(P(p[0].first, 0));
	set<P>::iterator itey = y.find(P(p[0].second, 0));
	if(itex !=  x.begin()) {
		ll cx = (*itex).first;
		--itex;
		ll nx = (*itex).first;
		q.push(P((cx - nx), (*itex).second));
		++itex;
	}
	if(itex !=  --(x.end())) {
		ll cx = (*itex).first;
		++itex;
		ll nx = (*itex).first;
		q.push(P((nx - cx), (*itex).second));
		--itex;
	}
	if(itey !=  y.begin()) {
		ll cy = (*itey).first;
		--itey;
		ll ny = (*itey).first;
		q.push(P((cy - ny), (*itey).second));
		++itey;
	}
	if(itey !=  --(y.end())) {
		ll cy = (*itey).first;
		++itey;
		ll ny = (*itey).first;
		q.push(P((ny - cy), (*itey).second));
		--itey;
	}
	x.erase(itex);
	y.erase(itey);
	while(!q.empty()) {
		P cp = q.top();
		q.pop();
		if(used[cp.second]) continue;
		used[cp.second] = true;
		res += cp.first;
		itex = x.find(P(p[cp.second].first, cp.second));
		itey = y.find(P(p[cp.second].second, cp.second));
		if(itex !=  x.begin()) {
			ll cx = (*itex).first;
			--itex;
			ll nx = (*itex).first;
			q.push(P((cx - nx), (*itex).second));
			++itex;
		}
		if(itex != --(x.end())) {
			ll cx = (*itex).first;
			++itex;
			ll nx = (*itex).first;
			q.push(P((nx - cx), (*itex).second));
			--itex;
		}
		if(itey !=  y.begin()) {
			ll cy = (*itey).first;
			--itey;
			ll ny = (*itey).first;
			q.push(P((cy - ny), (*itey).second));
			++itey;
		}
		if(itey !=  --(y.end())) {
			ll cy = (*itey).first;
			++itey;
			ll ny = (*itey).first;
			q.push(P((ny - cy), (*itey).second));
			--itey;
		}
		x.erase(itex);
		y.erase(itey);
	}
	cout<<res<<endl;
}