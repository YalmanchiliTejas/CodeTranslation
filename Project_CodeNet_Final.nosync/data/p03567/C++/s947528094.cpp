#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

string s; 

int main()
{
	cin>>s;
	
	bool chk=false;
	for(int i=0;i<s.size()-1;i++)
		if(s[i]=='A'&&s[i+1]=='C')
			chk=true;
			
	cout<<(chk?"Yes":"No")<<endl;
	return 0;
}