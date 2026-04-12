#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<iomanip>
#include<sstream>
#include<map>
#include<set>
#include<cmath>
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T& val) {
	std::fill((T*)array, (T*)(array + N), val);
}
#define rep(i,n) for(int i = 0;i < n;i++)
#define req(i,n) for(int i = 1;i <=n;i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
#define ALL(a) a.begin(),a.end()
typedef long long ll;
typedef long double ld;
const ll INF =  1LL << 60;
const int inf = 1 << 20;
int n, m, x, y, q, d,z, w = 0, sum, ans = 0;
vector<int>a;
const int MAX = 510000;
const int MOD = 1000000007;
int main(void) {
	cin >> n; int a[51][26]; string s;
	Fill(a, 0);
	rep(i, n) {
		cin >> s;
		rep(j, s.size()) {
			a[i][s[j] - 'a']++;
		}
	}s = "";
	for (char c = 'a'; c <= 'z'; c++) {
		m = c - 'a'; w = inf;
		rep(j, n) {
			w = min(w, a[j][m]);
		}
		rep(j, w) s = s + c;
	}cout << s << endl;
}