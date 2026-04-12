#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef long long ll;
ll n, par[100005], ans;
pair<pair<ll,ll>, ll> a[100005];
vector<pair<ll,pair<ll,ll> > > v;

ll Find (ll X) {
	if(par[X] == X) return X;
	return par[X] = Find(par[X]);
}

int main() {
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) {
		scanf("%lld%lld",&a[i].X.X,&a[i].X.Y);
		a[i].Y = i;
	}
	sort(a+1, a+1+n);
	for(int i=2;i<=n;i++) {
		v.push_back({a[i].X.X - a[i-1].X.X, {a[i].Y, a[i-1].Y}});
	}
	for(int i=1;i<=n;i++) {
		swap(a[i].X.X, a[i].X.Y);
	}
	sort(a+1, a+1+n);
	for(int i=2;i<=n;i++) {
		v.push_back({a[i].X.X - a[i-1].X.X, {a[i].Y, a[i-1].Y}});
	}
	sort(v.begin(), v.end());
	for(int i=1;i<=n;i++) par[i] = i;
	for(auto T : v) {
		ll V = T.X, A = T.Y.X, B = T.Y.Y;
		A = Find(A); B = Find(B);
		if(A != B) {ans += V; par[A] = B;}
	}
	printf("%lld\n",ans);
}
