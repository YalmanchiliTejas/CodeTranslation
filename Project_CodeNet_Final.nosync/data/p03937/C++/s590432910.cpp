#include<iostream>
#include<string>
using namespace std;
int h,w,sum;
int main()
{
	cin>>h>>w;
	for(int i=0;i<h;i++)
	{
		string s;
		cin>>s;
		for(int i=0;i<w;i++)
		{
			sum += (s[i]=='#');
		}
	}
    if(sum==h+w-1) cout<<"Possible\n";
    else cout<<"Impossible\n";
	return 0;
}