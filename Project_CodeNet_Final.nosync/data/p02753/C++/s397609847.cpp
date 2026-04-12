#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

#define x first
#define y second

#define INF 0x3f3f3f3f

using namespace std;

const int maxn = 1e5 + 10;

typedef long long LL;
typedef pair<int,int>PII;

int main(void) {
	string str;
	cin >> str;
	int a = 0,b = 0;
	for(int i = 0; i < str.length(); i ++) {
		if(str[i] == 'A') a ++;
		else b ++;
	}
	if(a == 3 || b == 3) {
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
	}
	return 0;
} 