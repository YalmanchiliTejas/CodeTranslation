#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
#define ref(i,x,y)for(int i=x;i<=y;++i)
string s;
int main()
{
cin>>s;
int n=s.size();
ref(i,0,n-2)if(s[i]=='A'&&s[i+1]=='C')
{
	cout<<"Yes"<<endl;
	return 0;
}
cout<<"No"<<endl;
}