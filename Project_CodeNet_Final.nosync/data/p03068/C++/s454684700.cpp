#include<bits/stdc++.h>
using namespace std;

string s;
int n,k;

int main(){
	cin>>n>>s>>k;
	k--;
	int x=s[k];
	for(int i=0;i<s.size();i++)
		if(s[i]!=x) s[i]='*';
	cout<<s;
	return 0;
}