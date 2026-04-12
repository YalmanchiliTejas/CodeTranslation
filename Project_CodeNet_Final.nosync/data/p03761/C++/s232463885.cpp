#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <numeric>
#include <climits>
#include <functional>
using namespace std;
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
using ll = long long;
const ll mod = 1000000007;
string al = "abcdefghijklmnopqrstuvwxyz";
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	int num[26] = { 0 };
	REP(i, 26) {
		num[i] = 100000;
	}
	REP(i, n) {
		int temp[26] = { 0 };
		string s; cin >> s;
		REP(j, s.size()) {
			REP(k, 26) {
				if (s[j] == al[k]) {
					temp[k]++;
				}
			}
		}
		REP(k, 26){
			num[k] = min(num[k], temp[k]);
		}
	}
	string str="";
	
	REP(k, 26) {
		REP(i, num[k]) {
			str += al[k];
		}
	}
	cout << str << endl;
	return 0;
}