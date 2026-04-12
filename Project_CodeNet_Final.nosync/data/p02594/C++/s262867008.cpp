#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<unordered_map>
#include<string>
#define LL long long
#define li i<<1
#define ri i<<1|1
using namespace std;
inline LL read()
{
    char c=getchar();LL x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
LL n; 
int main()
{
	n=read();
	if(n>=30)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
