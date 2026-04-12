#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>

using namespace std;

#define reps(i,f,n) for(int i=f;i<int(n);i++)
#define rep(i,n) reps(i,0,n)

int main()
{
	string s;
	cin>>s;
	
	bool ok = false;
	rep(i,s.size()-1)if(s[i]=='A' && s[i+1]=='C')ok=true;
	
	if(ok)puts("Yes");
	else puts("No");
	
}