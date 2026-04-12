#include<iostream>
#include<string>
#include<string>
#include<cstdio>
#include<math.h>
#include<map>
#include<set>
#include<queue>
#include<vector>

using namespace std;

int main()
{
	string s;
	string ans;
	cin >> s;
	int num = s.size() - 1;
	for (int i = 0; i < num; i++) {
		if ("AC" == s.substr(i, 2)) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No";
}