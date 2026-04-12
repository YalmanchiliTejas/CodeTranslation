#include<bits/stdc++.h>
using namespace std;
char s[100];
int main()
{
	cin>>s;
	for(int i=0;i<=strlen(s);i++) {
		if(s[i]=='A'&&s[i+1]=='C')
		{
			cout<<"Yes"<<endl;
			return 0; 				
		}
	}
	cout<<"No"<<endl;
	return 0;
}