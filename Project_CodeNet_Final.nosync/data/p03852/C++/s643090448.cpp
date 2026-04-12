#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <tuple>
#include <stack>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define print(s) cout << s << endl
typedef long long ll;
using namespace std;
ll mod = pow(10,9) + 7;
int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}
char upper(char c){
	return c-0x20;
}
char lower(char c){
	return c+0x20;
}
int main() {
	char c;
	cin >> c;
	const string vowel = "aeiou";
	cout << (vowel.find(c) != string::npos ? "vowel" : "consonant") << endl;
}