#include<bits/stdc++.h>
using namespace std;
string a;
int main()
{
	cin>>a;
	int l=a.size();
	for(int i=0;i<l-1;i++)if(a[i]=='A'&&a[i+1]=='C')
	{
		cout<<"Yes"<<endl;
		return 0;
	}
	cout<<"No"<<endl;
	return 0;
}