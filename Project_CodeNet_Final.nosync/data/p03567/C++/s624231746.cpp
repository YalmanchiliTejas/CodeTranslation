//A,Elebereth Gilthoniel mantae!
//For Temeria!
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<cstdio>
#include<map>
#include<stack>
#include<queue>
#include<cstring> 
using namespace std;

int main()
{
 	//freopen("","r",stdin);
	//freopen("","w",stdout);
	string s;cin>>s;for(int i=0;i<s.size()-1;i++)
	{
		if(s[i]=='A' and s[i+1]=='C')
		{
			cout<<"Yes";return 0;
		}
	} cout<<"No";
	return 0;
}