#include <iostream>
using namespace std;

int main() {
	long int i;
	string str;
	cin>>str;
	for(i=0;i<str.size();i++)
		{
			if(str[i]=='A'&& str[i+1]=='C')
				{
					cout<<"Yes"<<'\n';
					return 0;
				}
		}
	cout<<"No"<<'\n';	
	// your code goes here
	return 0;
}