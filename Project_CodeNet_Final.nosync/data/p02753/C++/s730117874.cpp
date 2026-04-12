#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long int lli;

int main()
{
	string s;
	cin >> s;

	if( s[0] != s[1] || s[0] != s[2] || s[1] != s[2] ) printf("Yes\n");
	else printf("No\n");
}