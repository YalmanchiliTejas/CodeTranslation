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
#define pll pair<ll,ll>
const int inf = 1000000001;
const ll INF = 2e18 * 2;
#define MOD 1000000007
#define mod 1000000009
#define pi 3.14159265358979323846
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };


int main() {
	int l, i;
	cin >> l;
	string s, t;
	cin >> s >> t;
	string s2 = s + s + t + t;
	string t2 = t + t + s + s;
	if (s2 > t2) {
		swap(s, t);
	}
	int a, b;
	for (a = l / s.size(); a >= 0; a--) {
		if ((l - a*s.size()) % t.size() == 0) {
			b = (l - a*s.size()) / t.size();
			break;
		}
	}
	string ans;
	for (i = 0; i < a; i++) {
		ans += s;
	}
	for (i = 0; i < b; i++) {
		ans += t;
	}
	string ans2;
	if (l%s.size() == 0) {
		for (int i = 0; i < l / s.size(); i++) {
			ans2 += s;
		}
		ans = min(ans, ans2);
	}
	ans2.clear();
	if (l%t.size() == 0) {
		for (int i = 0; i < l / t.size(); i++) {
			ans2 += t;
		}
		ans = min(ans, ans2);
	}
	ans2.clear();
	if ((l - s.size())%t.size() == 0) {
		ans2 += s;
		for (int i = 0; i < (l - s.size()) / t.size(); i++) {
			ans2 += t;
		}
		ans = min(ans, ans2);
	}
	ans2.clear();
	if ((l - t.size()) % s.size() == 0) {
		ans2 += t;
		for (int i = 0; i < (l - t.size()) / s.size(); i++) {
			ans2 += s;
		}
		ans = min(ans, ans2);
	}
	cout << ans << endl;
}