#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,a,n) for(int i = (a); i < (n); ++i)
using namespace std;
typedef long long ll;

void Main()
{
	char vowels[] = {'a','e','i','o','u'};
	char c; cin >> c;
	cout << (binary_search(vowels, vowels + 5, c) ? "vowel" : "consonant") << endl;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	Main();
}
