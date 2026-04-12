#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <numeric>
typedef long long ll;
using namespace std;
const int MOD = (int)1e9 + 7;
const ll INF = (ll)1e18 + 7;
//#define int long long
#define all(vec) vec.begin(), vec.end()
#define dbg(x) cerr << #x << " = " << (x) << endl

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct mystr{
	int minn = 500000;
	int cnt = 0;
};

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin>>N;
	mystr tmp[26];
	for (int i = 0; i < N; i++) {
		int cnttmp[26] = {0};
		int count[26] = {0};
		string s;
		cin>>s;
		for (int j = 0; j < s.size(); j++) {
			cnttmp[s[j] - 'a'] = 1;
			count[s[j] - 'a']++;
		}
		for (int j = 0; j < 26; j++) {
			tmp[j].minn = min(tmp[j].minn, count[j]);
			tmp[j].cnt += cnttmp[j];
		}
	}
	for (int i = 0; i < 26; i++) {
		if(tmp[i].cnt==N){
			for (int j = 0; j < tmp[i].minn; j++) {
				printf("%c", 'a' + i);
			}
		}
	}
	cout << endl;

	return 0;
}