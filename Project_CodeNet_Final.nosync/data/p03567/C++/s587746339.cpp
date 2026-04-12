#include "bits/stdc++.h"

using namespace std;

void solve()
{
	string s;
	cin >> s;
	regex re(".*AC.*");
	cout << (regex_match(s, re) ? "Yes" : "No") << endl;
}

int main(void)
{
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}
