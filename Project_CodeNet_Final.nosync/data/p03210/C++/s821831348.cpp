#include <iostream>
#include <string>
using namespace std;

int main()
{
	int age;
	string ans;
	
	cin>>age;
	
	if(age==5 || age==7 || age==3) 
		ans="YES\n";
	
	else 
		ans="NO\n";
	
	
	cout<<ans;
	
	return 0;
}