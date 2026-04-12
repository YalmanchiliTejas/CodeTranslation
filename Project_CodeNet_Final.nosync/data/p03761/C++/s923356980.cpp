#include <bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)(x.size()))
#define FOR(i,s,n) for (ll i = (s); (i) < (n); ++i)
#define FORD(i,s,l) for (ll i = (s); (i) >= l; --i)
#define F first
#define S second
#define TC int __tc; cin >> __tc; FOR(case_num,1,__tc+1)
#define TEST(x,i) ((x)&(1ll<<(i)))
#define SET(x,i) ((x)|(1ll<<(i)))
#define FLIP(x,i) ((x)^(1ll<<(i)))
#define CLEAR(x,i) ((x)&~(1ll<<(i)))

const double pi = 4 * atan(1);
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
const int MAXN = 200005;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<string> s(n,"");
	map<char,int> cnt;
	for (char c = 'a'; c <= 'z'; c++) {
		cnt[c]=1000;
	}
	for(int i = 0; i < n;i++){
		map<char,int> cnt2;
		for (char c = 'a'; c <= 'z'; c++) {
			cnt2[c]=0;
		}
		cin >> s[i];
		for (auto x : s[i]){
			cnt2[x]++;
		}
		for (auto p : cnt2) {
			cnt[p.F] = min(cnt[p.F],p.S);
		}
	}
	for (auto p : cnt) {
		while (p.S--) {
			cout << p.F; 
		}
	}
	cout << "\n";
	

}
