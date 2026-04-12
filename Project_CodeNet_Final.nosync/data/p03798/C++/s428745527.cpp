#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#define PI 3.14159265359
typedef long long ll;
const int MOD = 1e9+7;
const ll LLINF = 7e18;
using namespace std;


ll llmin(ll x, ll y){
	if (x < y) return x;
	return y;
}

ll llmax(ll x, ll y){
	if (x > y) return x;
	return y;
}

char rev(char c){
	if (c == 'S') return 'W';
	return 'S';
}

int n;
string s;

bool check1(string ans){
	if (ans[n-1] == 'S'){
		if (s[n-1] == 'o'){
			if (ans[0] == ans[n-2]){
				return true;
			}
		}
		if (s[n-1] == 'x'){
			if (ans[0] != ans[n-2]){
				return true;
			}
		}
	}
	if (ans[n-1] == 'W'){
		if (s[n-1] == 'o'){
			if (ans[0] != ans[n-2]){
				return true;
			}
		}
		if (s[n-1] == 'x'){
			if (ans[0] == ans[n-2]){
				return true;
			}
		}			
	}
	return false;
}

bool check2(string ans){
	if (ans[0] == 'S'){
		if (s[0] == 'o'){
			if (ans[1] == ans[n-1]){
				return true;
			}
		}
		if (s[0] == 'x'){
			if (ans[1] != ans[n-1]){
				return true;
			}
		}
	}
	if (ans[0] == 'W'){
		if (s[0] == 'o'){
			if (ans[1] != ans[n-1]){
				return true;
			}
		}
		if (s[0] == 'x'){
			if (ans[1] == ans[n-1]){
				return true;
			}
		}			
	}
	return false;
}

int main(){

	cin >> n >> s;
	string a[4] = {"SS", "SW", "WS", "WW"};

	for (int i = 0; i < 4; i++){
		string ans = a[i];
		for (int j = 2; j < n; j++){
			if (ans[j-1] == 'S'){
				if (s[j-1] == 'o'){
					ans.push_back(ans[j-2]);
				}
				if (s[j-1] == 'x'){
					ans.push_back(rev(ans[j-2]));
				}
			}
			if (ans[j-1] == 'W'){
				if (s[j-1] == 'o'){
					ans.push_back(rev(ans[j-2]));
				}
				if (s[j-1] == 'x'){
					ans.push_back(ans[j-2]);
				}
			}
		}
		if (check1(ans) && check2(ans)){
			cout << ans << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}