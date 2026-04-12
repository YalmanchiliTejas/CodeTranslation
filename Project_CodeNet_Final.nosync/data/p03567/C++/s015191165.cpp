#include<iostream>
#include<cstring>
#include<map>
#include<vector>
#include<set>
#include<cstring>
#include<algorithm>
#include<cmath>
#define Max zhi5968
typedef long long ll;
using namespace std;

int main ()
{
	string s;
	cin>>s;
	for(int i=1;i<s.length();i++)
		if(s[i]=='C'&&s[i-1]=='A')
		{
			cout<<"Yes"<<endl;
			return 0;
		}
	cout<<"No"<<endl;
	return 0;
}