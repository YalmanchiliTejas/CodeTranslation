#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 1000000007;
int main(){
	int n;
	cin >> n;
	int d[26] = {};
	string s;
	cin >> s;

	for(int i = 0;i < s.size();i++){
		d[s[i]-'a']++;
	}

	for(int i = 0;i < n-1;i++){
		string t;
		cin >> t;
		int now_d[26] = {};
		for(int j = 0;j < t.size();j++){
			now_d[t[j]-'a']++;
		}
		for(int j = 0;j < 26;j++){
			d[j] = min(d[j],now_d[j]);
		}
	}

	string ans = "";
	for(int i = 0;i < 26;i++){
		for(int j = 0;j < d[i];j++){
			ans += i + 'a';
		}
	}

	cout << ans << endl;
}
