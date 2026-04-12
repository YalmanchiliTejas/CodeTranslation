#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>

#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long LL;
using namespace std;

int main() {
	char  s[5]; cin >> s;

	if (s[0] != s[1] || s[1] != s[2]) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}