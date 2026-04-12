#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF (1LL << 55)
#define MOD (1000 * 1000 * 1000 + 7)
#define maxn 200111

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

vector<pii> v;
int ans[maxn];

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int a;
		scanf("%d", &a);
		v.pb(mp(a, i));
	}

	sort(v.begin(), v.end());
	int l = v[n / 2 - 1].fi;
	int d = v[n / 2].fi;

	for(int i = 0; i < n / 2; i++)
		ans[v[i].se] = d;

	for(int i = n / 2; i < n; i++)
		ans[v[i].se] = l;

	for(int i = 1; i <= n; i++)
		printf("%d\n", ans[i]);
	
	return 0;
}