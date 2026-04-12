#include<bits/stdc++.h>

#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define nyan "(=^･ω･^=)"
#define mkp make_pair
#define lP pair<ll, ll>
#define iP pair<int,int>

using namespace std;
typedef long long ll;

char c;

int main() {
	cin >> c;
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		cout << "vowel" << endl;
	}
	else {
		cout << "consonant" << endl;
	}
	return 0;
}