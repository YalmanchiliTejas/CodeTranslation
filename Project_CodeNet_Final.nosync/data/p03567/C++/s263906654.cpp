#include<iostream>
#include<string>
using namespace std;
string s;
int main()
{
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++)
	{
        if(s[i]=='A'&&s[i+1]=='C')
		{
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
	return 0;
}