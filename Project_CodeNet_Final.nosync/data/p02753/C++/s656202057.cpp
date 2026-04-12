#include<bits/stdc++.h>
using namespace std;

string s;
int c1,c2;

int main()
{
	cin>>s;
	for(int i=0;i<=2;++i) {
		if(s[i]=='A') c1++;
		else if(s[i]=='B') c2++;
	}
	if(c1&&c2) printf("Yes");
	else printf("No");
}