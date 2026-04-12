#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
const int mod = 1000000007;
#define ll long long

int main()
{
	char s; cin >> s;
	if (s == 'a' || s == 'i' || s == 'u' || s == 'o' || s == 'e') {
		cout << "vowel" << endl;
	}
	else cout << "consonant" << endl;
}