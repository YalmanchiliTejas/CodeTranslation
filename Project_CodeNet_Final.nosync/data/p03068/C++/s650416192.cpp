#include<iostream>
#include<string>
using namespace std;

int a,b,c;
string s;
int main(){
	cin>>a>>s>>b;//s[b-1]
	string ans;
	for (int i = 0; i < a; i++)
	{
		if (s[i]!=s[b-1])
		{
			ans+='*';
		}else{
			ans+=s[i];
		}
	}
	cout<<ans<<endl;
}