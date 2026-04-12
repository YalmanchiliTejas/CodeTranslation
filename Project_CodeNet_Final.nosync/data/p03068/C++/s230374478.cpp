#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define elif else if
int a,b,c;
string s;
signed main()
{
	cin>>a>>s>>b;
	rep(i,a){
		if(s[i]!=s[b-1]){
			cout<<'*';
		}else{
			cout<<s[i];
		}
	}
}