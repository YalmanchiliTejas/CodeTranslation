#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

int main() {
	int n;
	string o[52],s[52],much;
	cin >> n;
	rep(i, 0, n) {
		cin >> o[i];
		s[i] = o[i];
		//cout << s[i] << " " << o[i] << endl;
	}
	rep(i, 0, s[0].size()) {
		char m = s[0][i];
		//cout << m <<" "<<"start"<< endl;
		bool flag = true;
		rep(j, 1, n) {
			if (s[j].find(m) == -1) {
				flag = false;
				break;
			}
		}
		if (flag == true) {
			rep(j, 0, n) {
				//cout << s[j].find(m) << endl;
				//s[j].erase(s[j].begin() + s[j].find(m),s[j].end());
				s[j].replace(s[j].find(m), 1, "*");
				//cout << s[j]<< endl;
			}
			much += m;
		}
	}
	sort(much.begin(), much.end());
	cout << much << endl;
}