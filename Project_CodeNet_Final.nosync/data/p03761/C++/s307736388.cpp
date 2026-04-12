#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <numeric>
#include <math.h>
#include <algorithm>
#include <functional>
#include <string>
#include <array>
#include <vector>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#include <complex>
#include <bitset>
#define full(c) c.begin(), c.end()
#define vector2d(name,type,h,w,init) vector<vector<type>> name(h,vector<type>(w,init)) 
const int PRIME = 1000000007;
const int INT_INF = 2147483647;
const long long int LL_INF = 9223372036854775807;
const double PI = acos(-1);
const double EPS = 0.000000001;
typedef unsigned long long int ull;
typedef long long int ll;
using namespace std;

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	int k, i, n;
	string str;
	cin >> n;
	vector2d(cnt, int, 26, n, 0);
	for (k = 0; k < n; k++){
		string s;
		cin >> s;
		for (i = 0; i < s.size(); i++) cnt[s[i] - 'a'][k]++;
	}
	for (k = 0; k < 26; k++){
		int len = *min_element(full(cnt[k]));
		for (i = 0; i < len; i++) str += (char)(k + 'a');
	}
	cout << str << endl;
	return 0;
}