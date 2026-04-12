#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using ll = long long int;
const int mod = 1e9 + 7;
#define rep(i, a, b) for(int i = a;i < b; i++)

int main() {

	string s;
	cin >> s;

	if (s == "AAA" || s == "BBB") cout << "No" << endl;
	else cout << "Yes" << endl;

	return 0;
}