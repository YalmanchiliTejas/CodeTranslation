#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int n=0;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]=='A'&s[i+1]=='C')
		{
			n++;
			cout<<"Yes"<<endl;
			break;
		} 
	}
	if(n==0)
	cout<<"No"<<endl;
	return 0;
}