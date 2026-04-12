#include<bitset>
#include<math.h>
#include<limits.h>
#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<sstream>
#include<list>
#include<queue>
#include<algorithm>
#include<functional>
#include<map>
#include<set>
#include<utility>
#include<initializer_list>
#include<tuple>
#include<regex>
using namespace std;
#define ull unsigned long long
#define ll long long
#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define rep1n(i, n) for(int i=1;i<=(int)(n);i++)
#define all(t) t.begin(), t.end()
#define rall(t) t.rbegin(), t.rend()
#define mat(type, row, col, init) vector<vector<type>>(row, vector<type>(col, init));
#define Yes(cond) cout<<(cond? "Yes":"No")<<endl;
#define YES(cond) cout<<(cond? "YES":"NO")<<endl;
int main() {
	int n;
	cin >> n;
	vector<string>s(n);
	rep(i, n)cin >> s[i];
	vector<map<char, int>>m(n);
	rep(i, n)rep(j, s[i].size())m[i][s[i][j]]++;
	int ans = 0;
	map<char, int>minmap;
	for (char i = 'a'; i <= 'z'; i++) {
		auto mi = [&]()->int {
			int minn = 5000;
			rep(j, n) {
				minn = min(m[j][i], minn);
			}
			return minn;
		};

		minmap[i] = mi();
		ans += minmap[i];
		rep(j, minmap[i])cout << i;
	}




	cout << endl;

	return 0;
}



