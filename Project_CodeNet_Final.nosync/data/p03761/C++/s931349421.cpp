#include<iostream>
#include<string>
using namespace std;
int mat[100001][27];
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string ss;
		cin>>ss;
		for(int j=0;j<ss.size();j++)
		mat[i][ss[j]-'a']++;
	}
	string skraj="";
	for(int i=0;i<=25;i++)
	{
		int maxi=1e9;
		for(int j=0;j<n;j++)
			maxi=min(maxi,mat[j][i]);
		for(int j=0;j<maxi;j++)
			skraj+=(i+'a');
	}
	cout<<skraj<<endl;
return 0;
}