#include<bits/stdc++.h>
using namespace std;
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
int main()
{
    io
    string s;
	cin >> s;
	if((s[0] == 'A'&& s[1] == 'A' && s[2] == 'A' ) || (s[0] == 'B' && s[1] == 'B' && s[2] == 'B'))
	{
		cout << "No\n";
	}
	else cout << "Yes\n";
    
    return 0;
}