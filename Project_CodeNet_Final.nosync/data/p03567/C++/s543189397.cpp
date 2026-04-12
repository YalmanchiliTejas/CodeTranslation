#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	cin>>s;
	for (int i=0;i<s.size()-1;i++)
		if (s[i]=='A'&&s[i+1]=='C') return puts("Yes"),0;
	puts("No");
	return 0;
}