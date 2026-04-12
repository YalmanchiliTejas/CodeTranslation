#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
using namespace std;
using ll=long long;

int main(){
	int n,k;
	string s;

	cin>>n>>s>>k;

	for(int i=0;i<n;i++)
		if(s[k-1]!=s[i])s[i]='*';
	cout<<s;
}