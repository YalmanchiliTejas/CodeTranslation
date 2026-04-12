#include<iostream>
#include<string>
#include <vector>
#include<queue>
#include<map>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<bitset>
using namespace std;
using vi = vector<int>;
using vii = vector<vi>;
using vs = vector<string>;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,m,n) for(int i=m;i<n;i++)
#define vsort(v) sort(v.begin(), v.end())
#define rv(v) reverse(v.begin(), v.end())
#define ll long long
#define PI 3.141592653589793
using vll = vector<ll>;
using Graph = vii;
const ll MOD = 1e9 + 7;


int main() {
	int h, w;
	cin >> h >> w;
	vector<string> a(h);
	rep(i, h) cin >> a[i];
	int cnt = 0;
	rep(i, h) {
		rep(j, w) {
			if (a[i][j] == '#') cnt++;
		}
	}
	string ans = (h + w - 1 == cnt) ? "Possible" : "Impossible";
	cout << ans << endl;
}