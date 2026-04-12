#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;
int main()
{
	string c;
	cin>>c;
	if (c.find("AC") != std::string::npos)
		puts("Yes");
	else
	cout<<"No";

	return 0;
}
	
