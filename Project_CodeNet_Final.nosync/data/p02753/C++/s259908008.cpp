#include<bits/stdc++.h>
#define ll long long
using namespace std;
char c[10]; 
inline int read()
{
	int x=0,ff=1;
	char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-') ff=-1;ch=getchar();}
	while(isdigit(ch)) {x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*ff;
}
int main()
{
	//freopen("1.in","r",stdin);
	scanf("%s",c);
	if(c[0]==c[1]&&c[1]==c[2]) puts("No");
	else                 puts("Yes");
	return 0;
}
