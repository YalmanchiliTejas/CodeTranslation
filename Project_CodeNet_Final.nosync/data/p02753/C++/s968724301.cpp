#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cctype>
#include<cstring>
#define maxn 2007
#define SDOI2020 RP++ 
using namespace std;
char a,b,c; 
inline int read()
{
	int x=0;
	int flag=0;
	char ch;
	ch=getchar();
	while(!isdigit(ch)) 
	{
		if(ch=='-') flag=1;
	ch=getchar();	
	}
	while(isdigit(ch))
	{
		x=(x<<3)+(x<<1)+ch-48;
		ch=getchar();
		}
		if(flag==1) x=-x;	
		return x;
}


int main()
{
	cin>>a>>b>>c;
	if(a != b || b != c)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	
	return 0;
} 