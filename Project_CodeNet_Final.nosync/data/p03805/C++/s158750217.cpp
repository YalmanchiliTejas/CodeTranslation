#include "bits/stdc++.h"
using namespace std;

#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cout<<" "<<v[i]; cout<<endl

typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
const int inf = 1000000001;
const ll INF = 1e16;
#define MOD 1000000007
#define mod 1000000009
#define pi 3.14159265358979323846
#define Sp(p) cout<<setprecision(15)<<fixed<<p<<endl;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };

int main() {
	int n, m, i, j;
	cin >> n >> m;
	vector<pii> a(m);
	for (i = 0; i < m; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end());
	vi v(n-1);
	for (i = 0; i < n-1; i++) {
		v[i] = i + 2;
	}
	int ans = 0;
	do {
		int now = 1;
		bool flag1 = true;
		for (i = 0; i < n - 1; i++) {
			bool flag = false;
			int next = v[i];
			for (j = 0; j < m; j++) {
				if (a[j].first == min(now, next) && a[j].second == max(now, next)) {
					flag = true;
				}
			}
			if (flag) {
				now = next;
			}
			else {
				flag1 = false;
			}
		}
		if (flag1) {
			ans++;
		}
	} while (next_permutation(v.begin(), v.end()));
	cout << ans << endl;
}