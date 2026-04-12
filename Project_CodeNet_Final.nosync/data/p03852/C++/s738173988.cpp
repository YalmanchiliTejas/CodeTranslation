#include <iostream>

using namespace std;
typedef long long  ll;
#define rep(i,s,n)for(ll i = s;i<n;i++)

int main() {
	char a; cin >> a;

	cout << ((a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') ? "vowel" : "consonant") << endl;

	return 0;
}