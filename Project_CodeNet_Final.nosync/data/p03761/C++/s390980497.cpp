#include <stdio.h>
#include<iostream>
#include<algorithm>
#include <string.h>
#include<string>
#include<vector>
#include<map>
using namespace std;
int mp[55][26];
int fi[27];
int main()
{	
	/*freopen("input.txt","r",stdin);*/
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		/*cout<<s[0]-'a'+1<<endl;*/
		for(int j=0;j<s.length();j++)
			mp[i][s[j]-'a'+1]++;
	}
	fill(fi,fi+27,10000);
	for(int i=1;i<=26;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(mp[j][i]<fi[i])
				fi[i]=mp[j][i];
		}
	}
	for(int i=1;i<=26;i++)
	{
		if(fi[i]==0) continue;
		for(int j=1;j<=fi[i];j++)
			printf("%c",i-1+'a');
	}
	printf("\n");
	return 0;
}