#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define repb(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define o(a) cout<<a<<endl
#define int long long
#define fi first
#define se second
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;


signed main() {
	int m, n, f, y, c, p;
	double r;
	cin >> m;
	rep(x, 0, m) {
		int MAX = 0;
		cin >> c >> y >> n;
		rep(i, 0, n) {
			cin >> f >> r >> p;
			int a = c;
			if (f) {
				rep(i, 0, y){
					a += (int)((double)a*r) - p;
				}
			}
			else {
				int sum = 0;
				rep(i, 0, y) {
					sum += (int)((double)a*r);
					a -= p;
				}
				a += sum;
			}
			MAX = max(MAX, a);
		}
		cout << MAX << endl;
	}
}