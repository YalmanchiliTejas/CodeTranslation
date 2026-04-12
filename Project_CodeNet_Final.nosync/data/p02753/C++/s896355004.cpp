#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main() {
	// your code goes here
	string s;
	cin>>s;
	int a[2];
	a[0]=a[1]=0;
	for(int i=0;i<s.length();i++)
	a[s[i]-'A']++;
	if(a[0]==0 || a[1]==0)
	cout<<"No";
	else
	cout<<"Yes";
	return 0;
}
