#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int main(){
	cin>>s;
	bool a=0,b=0;
	for(int i=0;i<s.size();i++)if(s[i]=='A')a=1; else b=1;
	if(a&&b)cout<<"Yes";
	else cout<<"No";
    return 0;
}