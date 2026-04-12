#include<cstdio>
#include<set>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long ll;
typedef set<pair<ll, ll> >::iterator ite;
const int MAXN = 200010;
const ll INF = 1LL<<60;
int n, f1, f2;
ll x[MAXN], y[MAXN], ans = INF;
ll Rmin = INF, Rmax, Bmin = INF, Bmax; 
bool f;
set<pair<ll, ll> > S;

inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	for(; !isdigit(ch); ch = getchar()) if(ch=='-') f=-1;
	for(; isdigit(ch); ch = getchar()) x = x*10 + ch-'0';
	return x * f;
}

inline ll calc(int x, int y) {
	ll d1 = max(Rmax-Rmin,max(x-Rmax, Rmin-x));
	ll d2 = max(Bmax-Bmin,max(y-Bmax, Bmax-y));
	return d1*d2;
}

int main() {
	int i;
	n = read();
	for(i = 1; i <= n; i++) {
		x[i] = read(), y[i] = read();
		if(x[i] < y[i]) swap(x[i], y[i]);
		Rmax = max(Rmax, x[i]);
		Bmin = min(Bmin, y[i]);
		Rmin = min(Rmin, x[i]);
		Bmax = max(Bmax, y[i]);
	}
	ans = min(ans, (Rmax-Rmin)*(Bmax-Bmin));
	Rmin = Bmin;
	for(i = 1; i <= n; i++) {
		if(x[i] == Rmax) f1++;
		if(y[i] == Rmin) f2++;
		if(x[i] == Rmax && y[i] == Rmin) f = true;
	}
	if(f&&f1==1&&f2==1) return 0;
	for(i = 1; i <= n; i++) S.insert(make_pair(y[i], i));
	while(true) {
		ite it = S.end();
		it--;
		ans = min(ans, (Rmax-Rmin)*((*it).first-(*S.begin()).first));
		if((*S.begin()).second != -1) {
			int id = (*S.begin()).second;
			S.erase((*S.begin()));
			S.insert(make_pair(x[id], -1));
		}
		else break;
	}
	printf("%lld\n", ans);
	return 0;
}
