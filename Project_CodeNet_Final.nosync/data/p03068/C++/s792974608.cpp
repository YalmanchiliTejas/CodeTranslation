#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k;
	string s;
	cin>>n;
	cin>>s;
	cin>>k;
	char p = s[k-1];
	int count = 0;
	for(int i=0;i<s.size();i++){
		if(s[i]!=p)s[i]='*';
	}
	cout<<s<<endl;
}
