#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	string s;//1111111
	getline(cin,s);
	for(int i=0;i<s.size();i++) {
		if(s[i]=='A' && s[i+1]=='C') {
			cout<<"Yes";
			return 0;//1111111
		}
	}
	cout<<"No";
	return 0;
}