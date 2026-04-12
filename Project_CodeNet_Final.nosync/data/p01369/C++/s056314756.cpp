#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#include<ctime>
#include<cstring>
#include<numeric>

#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;

using namespace std;

const int LEFT = -1;
const int RIGHT = 1;

int check(char c) {
	string left = "qazwsxedcrfvtgb";
	if(left.find(c) != string::npos) {
		return LEFT;
	} else {
		return RIGHT;
	}
}

int main() {
	string str;	
	while(cin >> str) {
		if(str == "#") break;
		int ans = 0;
		REP(i, 1, str.size()) {
			if(check(str[i-1]) != check(str[i])) {
				ans++;	
			}
		}
		cout << ans << endl;
	}
	return 0;
}