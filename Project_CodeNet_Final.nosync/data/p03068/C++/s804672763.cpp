#include <iostream>
using namespace std;
 
int main() {
	int n;
	cin>>n;
	string s;
	cin>>s;
	int k;
	cin>>k;
	char ch=s[k-1];
	string ans="";
	for(int i=0;i<s.size();i++)
		if(s[i]!=ch)
			ans+='*';
		else
			ans+=s[i];
	cout<<ans<<endl;
	return 0;
}