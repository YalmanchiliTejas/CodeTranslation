#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s1;
	int a=0,b=0;
	cin>>s1;
	for(int i=0;i<3;i++) 
		if(s1[i]=='A') a++;
		else b++;
	if(a==0||b==0) cout<<"No"<<endl;
	else cout<<"Yes"<<endl; 
	
	
	return 0;
} 