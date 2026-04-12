#pragma GCC optimize("O2")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<limits.h>
#include<ctime>
#define N 100001
typedef long long ll;
const int inf=0x3fffffff;
const int maxn=2017;
using namespace std;
inline int read()
{
    int f=1,x=0;char ch=getchar();
    while(ch>'9'|ch<'0')
    {
        if(ch=='-')
        f=-1;
        ch=getchar();
    }
    while(ch<='9'&&ch>='0')
    {
        x=(x<<3)+(x<<1)+ch-'0';
        ch=getchar();
    }
    return f*x;
}char s[N];
int main()
{
	scanf("%s",s+1);
	for(int i=1;i<=strlen(s+1);i++)
	{
		if(s[i+1]=='C'&&s[i]=='A')
		{
			cout<<"Yes";return 0;
		}
		
	}
	cout<<"No";
}