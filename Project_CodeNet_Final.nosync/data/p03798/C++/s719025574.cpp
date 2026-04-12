#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <cmath>   
#include<cctype>
#include<string>
#include<set>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include <deque>
#include <typeinfo>
#include <utility> 
#define all(x) (x).begin(),(x).end()
#define rep(i,m,n) for(int i = m;i < n;++i)
using namespace std;
using ll = long long;
using R = double;
const ll inf = 1LL << 50;
const ll MOD = 1e9 + 7;

int n;
string s[101010];


int main() {
	cin >> n;
	string tempstr;
	cin >> tempstr;
	rep(i, 0, n) {
		s[i] = tempstr[i];
	}
	string t[2] = {"S","W"};
	rep(i, 0, 2)rep(j, 0, 2) {
		vector<string>temp(n);
		temp[0] = t[i];
		temp[n - 1] = t[j];
		map<vector<string>, string>mp;
		mp[{"W", "W", "o"}] = "S";
		mp[{"S", "W", "o"}] = "W";
		mp[{"W", "S", "o"}] = "W";
		mp[{"S", "S", "o"}] = "S";
		mp[{"W", "W", "x"}] = "W";
		mp[{"S", "W", "x"}] = "S";
		mp[{"W", "S", "x"}] = "S";
		mp[{"S", "S", "x"}] = "W";
		for (int k = 0; k < n-2 ; k++) {
			vector<string>v;
			if (k != 0) {
				v.push_back(temp[k-1]);
				v.push_back(temp[k]);
				v.push_back(s[k]);
				temp[k + 1] = mp[v];
			}
			else {
				v.push_back(temp[n - 1]);
				v.push_back(temp[0]);
				v.push_back(s[0]);
				temp[1] = mp[v];
			}
		}
		if (mp[{temp[n - 3], temp[n - 2], s[n - 2]}] == temp[n - 1]) {
			bool ok = 0;
			if (temp[n-1]=="W") {
				if ((s[n-1]=="o" && temp[n-2]!=temp[0])||(s[n-1]=="x" && temp[n-2]==temp[0])) {
					ok = 1;
				}
			}
			else {
				if ((s[n - 1] == "o" && temp[n - 2] == temp[0]) || (s[n - 1] == "x" && temp[n - 2] != temp[0])) {
					ok = 1;
				}
			}
			if (ok) {
				rep(i, 0, n) {
					cout << temp[i];
				}
				cout << endl;
				exit(0);
			}
		}
	}

	cout << "-1" << endl;
	
	return 0;
}