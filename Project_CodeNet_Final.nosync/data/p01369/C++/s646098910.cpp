#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
map<char,int>M;
main()
{
	string t="qwertasdfgzxcvb";
	for(int i=0;i<t.size();i++)M[t[i]]=1;
	while(cin>>t,t!="#")
	{
		int cnt=0,n=M[t[0]];
		for(int i=1;i<t.size();i++)
		{
			if(n!=M[t[i]])cnt++;
			n=M[t[i]];
		}
		cout<<cnt<<endl;
	}
}
