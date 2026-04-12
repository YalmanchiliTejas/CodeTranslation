#include <string>
#include <iostream>
using namespace std;

int main()
{
	string s;
	int i;
	cin >> s;
	for(i=0;i<s.size()-1;i++)
		if(s[i]=='A' && s[i+1]=='C') break;
	if(i==s.size()-1) cout << "No\n"; 
	else cout << "Yes\n";
}