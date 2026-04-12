#include<iostream>
#include<iomanip>
#include<string>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;
#define LL long long
#define MOD 100000
#define inf 1999999999


int main() {
	int a[10];
	char s;
	set<char> v = { 'a','i','u','e','o' };
	cin >> s;
	if(v.count(s))cout << "vowel" << endl;
	else cout << "consonant" << endl;
	return 0;
}
