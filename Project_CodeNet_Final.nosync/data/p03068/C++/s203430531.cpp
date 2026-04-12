#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstdlib>

using namespace std;

int main(void) {
	int n,k,c[28]={};
	string s;
	cin>>n>>s>>k;

	c[s[k-1]-'a']++;

	for (int i = 0; i < n; i++) {
		if(c[s[i]-'a']==0)s[i]='*';
	}

	cout<<s<<"\n";


	return 0;
}
