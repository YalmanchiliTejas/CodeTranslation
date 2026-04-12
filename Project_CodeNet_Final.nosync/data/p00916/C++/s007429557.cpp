#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
struct rect { int x1, x2, y1, y2; };
int invx[1 << 20],invy[1<<20];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main(){
	int n;
	while (cin >> n, n) {
		vector<int> vx, vy;
		rect a[50];
		rep(i, n) {
			int x1, x2, y1, y2;
			cin >> x1 >> y2 >> x2 >> y1;
			a[i] = { x1,x2,y1,y2 };
			vx.push_back(x1);
			vx.push_back(x2);
			vy.push_back(y1);
			vy.push_back(y2);
		}
		sort(vx.begin(), vx.end());
		sort(vy.begin(), vy.end());
		int cnt = 0;
		rep(i, (int)vx.size()) {
			if (i - 1 >= 0 && vx[i] == vx[i - 1])continue;
			invx[vx[i]] = cnt; cnt++;
		}
		cnt = 0;
		rep(i, (int)vy.size()) {
			if (i - 1 >= 0 && vy[i] == vy[i - 1])continue;
			invy[vy[i]] = cnt; cnt++;
		}
		rep(i, n) {
			a[i].x1 = invx[a[i].x1];
			a[i].x2 = invx[a[i].x2];
			a[i].y1 = invy[a[i].y1];
			a[i].y2 = invy[a[i].y2];
		}
		ll mp[200][200];
		rep(i, 200) {
			rep(j, 200) {
				mp[i][j] = 0;
			}
		}
		rep(i, n) {
			Rep(j, a[i].x1, a[i].x2) {
				Rep(k, a[i].y1, a[i].y2) {
					mp[j+50][k+50] += (ll)1 << i;
				}
			}
		}
		int out = 0;
		bool used[200][200];
		rep(i, 200) {
			rep(j, 200) {
				used[i][j] = false;
			}
		}
		rep(i, 200) {
			rep(j, 200) {
				if (used[i][j])continue;
				queue<P> q;
				used[i][j] = true;
				q.push({ i,j });
				while (!q.empty()) {
					P x = q.front(); q.pop();
					rep(k, 4) {
						int nx = x.first + dx[k];
						int ny = x.second + dy[k];
						if (nx < 0 || ny < 0 || nx == 200 || ny == 200)continue;
						if (used[nx][ny])continue;
						if (mp[x.first][x.second] != mp[nx][ny])continue;
						used[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
				out++;
			}
		}
		cout << out << endl;
	}
	return 0;
}
