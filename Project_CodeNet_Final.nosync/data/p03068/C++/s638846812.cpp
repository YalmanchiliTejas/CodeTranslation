#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
typedef long long ll;
ll N[maxn];
int main()
{
	int n,k;string s;cin>>n;cin>>s;cin>>k;
	char c=s[k-1];
	for(int i=0;i<s.length();i++)
	{
		if(c==s[i]) printf("%c",s[i]);
		else printf("*");
	}
	
 } 