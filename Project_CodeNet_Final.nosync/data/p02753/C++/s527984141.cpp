#include <iostream>
using namespace std;
int main()
{
	bool A=false,B=false;
	string s;
	cin>>s;
	for(int i=0;i<s.size();++i) 
	{
		if(s[i]=='A') A=true;
		else B=true;
	}
	if(A==true && B==true) cout<<"Yes";
	else cout<<"No";
	return 0;
}