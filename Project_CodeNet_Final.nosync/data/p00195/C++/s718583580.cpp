#include<iostream>
#include<iomanip>
#include<algorithm>
#include<array>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<functional>
#include<limits>
#include<list>
#include<map>
#include<numeric>
#include<set>
#include<stack>
#include<string>
#include<sstream>
#include<unordered_map>
#include<queue>
#include<vector>
using namespace std;

//#define int long long
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(a) (a).begin(),(a).end()
#define dump(o) {cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) {cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
const int MOD = 1e9 + 7;
string s = "ABCDE";
signed main() {
	int s1[5], s2[5], sum[5];
	for (; cin >> s1[0] >> s2[0] && s1[0];) {
		rep(i, 1, 5)cin >> s1[i] >> s2[i];
		rep(i, 0, 5)sum[i] = s1[i] + s2[i];
		cout << s[max_element(sum, sum + 5) - sum] << " " << *max_element(sum, sum + 5) << endl;
	}
	return 0;
}