#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,k,i;
	string s;
	cin>>n>>s>>k;
	k--;
	for(i=0;i<n;i++)
	{
		if(s[i]!=s[k])
			cout<<"*";
		else
			cout<<s[i];
	}
	cout<<endl;
	return 0;
}