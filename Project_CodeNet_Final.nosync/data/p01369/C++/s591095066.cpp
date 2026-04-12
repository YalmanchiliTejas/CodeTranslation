#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
typedef unsigned int ui;
int main(){
	int right[26] = {};
	for (int i = 7; i <= 15; i++) {
		right[i] = 1;
	}
	right[20] = 1; right[24] = 1;
	string s;
	while (cin >> s) {
		if (s == "#")break;
		int len = s.length();
		int count = 0;
		for (int i = 0; i < len-1; i++) {
			if (right[s[i]-'a'] != right[s[i + 1]-'a'])count++;
		}
		cout << count << endl;
	}
	return 0;
}
