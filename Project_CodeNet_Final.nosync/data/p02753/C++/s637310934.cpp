#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

string s;
int c1,c2;

int main()
{
	cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='A') c1++;
        else c2++;
    }
    if(c1==s.length()||c2==s.length()) puts("No");
    else puts("Yes");
	return 0;
}