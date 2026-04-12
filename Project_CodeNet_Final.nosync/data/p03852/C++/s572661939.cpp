#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using P = pair<llong, llong>;

#define BE(x) x.begin(), x.end()

const llong inf = llong(1e18)+7;
const llong mod = 1e9+7;

int main(){
	char a;
	cin >> a;
	if(a == 'a' || a == 'i' || a == 'u' || a == 'e' || a == 'o')
		cout << "vowel" << endl;
	else
		cout << "consonant" << endl;

	return 0;
}