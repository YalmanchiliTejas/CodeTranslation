#include <iostream>
using namespace std;

int main() {
	string s;
	int count=0;
	cin>>s;
	for(int i=0;i<3;i++)
	{
	    if(s[i]=='A')
	    count++;
	}
	if(count<=2 && count>0)
	cout<<"Yes";
	else
	cout<<"No";
	return 0;
}