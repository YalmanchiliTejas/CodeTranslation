#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;
const int maxn = 200105;
vector<pair<int,int>>a[maxn];
ll mx[maxn<<2], lz[maxn<<2];
void update(int x, int l, int r, int ql, int qr, ll v) {
	if (ql <= l && qr >= r) {
		mx[x] += v;
		lz[x] += v;
		return;
	}
	int mid = (l + r) >> 1;
	if (ql <= mid) {
		update(x<<1, l, mid, ql, qr, v);
	}
	if (qr > mid) {
		update(x<<1|1, mid + 1, r, ql, qr, v);
	}
	mx[x] = max(mx[x << 1], mx[x << 1 | 1]) + lz[x];
}
void go() {
	int n, m;
	cin >> n >> m;
	f (m) {
		int x, y, z;
		cin >> x >> y >> z;
		a[y].pb({x, z});
	}
	f1(n) {
		update(1,1,n,i,i,mx[1]);
		for (auto &j : a[i]) {
			update(1,1,n,j.F, i, j.S);
		}
	}
	cout << max(mx[1],0LL) << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c = 0;
    int t;
    if (!c) {
        t = 1;
    }
    else {
        cin >> t;
    }
    while (t--) {
        go();
    }
}