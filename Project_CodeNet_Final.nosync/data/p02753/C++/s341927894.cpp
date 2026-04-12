#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<stack>
#include<vector>
#include<queue>
#include<set>
#include<utility>
#define INF 0x3f3f3f3f
#define PI acos(-1)
#define ll long long
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	string s;
	cin >> s;
	bool flag = false;
	for (int i = 0; i < s.length()-1;i++) {
		if (s[i]-s[i+1]==1||s[i]-s[i+1]==-1) {
			flag = true;
			break;
		}
	}
	if (flag) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}
