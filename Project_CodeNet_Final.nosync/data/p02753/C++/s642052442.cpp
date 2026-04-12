#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin.exceptions(cin.failbit);
     
    string s;
    cin >> s;
    bool a = false; bool b = false;
    for (int i=0;i<s.length();i++)
    {
    	if (s[i]=='A') a = true;
    	if (s[i]=='B') b = true;
    }
	if (a & b) cout << "Yes\n";
	else cout << "No\n";	
	return 0;
}
	