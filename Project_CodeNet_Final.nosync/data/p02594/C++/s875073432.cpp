//author: clorf
//Think twice,Code once.
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<ctime>
#define INF 1e9
using namespace std;
const int maxn=100010;
const double Pi=acos(-1.0);
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0'||ch>'9') {f|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=f?-x:x;
	return;
}
int x;
int main()
{
	scanf("%d",&x);
	if(x>=30)
		printf("Yes");
	else
		printf("No");
	return 0;
}