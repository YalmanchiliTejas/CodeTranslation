#include<iostream> 
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath> 
#include<algorithm> 
using namespace std;
const int maxn=500010,inf=1e9;
int n;
char s[maxn];
inline void read(int &k)
{
	int f=1;k=0;char c=getchar();
	while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();
	while(c<='9'&&c>='0')k=k*10+c-'0',c=getchar();
	k*=f;
}
int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<n;i++)
	if(s[i]=='A'&&s[i+1]=='C')return puts("Yes"),0;
	puts("No");
}