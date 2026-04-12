
#include <iostream>
#include <cstring>

using namespace std;

int ans1,ans2;

int main()
{
	string s;
	cin>>s;
	
	for (int i=0;i<=2;++i)
		if (s[i]=='A')
			ans1++;
		else
			ans2++;
			
	if (ans1==0 || ans2==0){
		cout<<"No"<<endl;
		return 0;
	}
	
	cout<<"Yes"<<endl;
	
	return 0;
}