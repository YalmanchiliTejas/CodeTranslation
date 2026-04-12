#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	void solve() {
		string s;
		cin >> s;
		for(int i=0; i < 3; i++){
			for(int j=0; j < 3; j++){
				if(s[i] != s[j]){
					cout << "Yes\n";
					return;
				}
			}
		}
		cout << "No\n";
		return;
	};
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	Solution solution;
	solution.solve();
	return 0;
}