#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N=1e5+5;
template<class T>inline void read(T &res)
{
char c;T flag=1;
while((c=getchar())<'0'||c>'9')if(c=='-')flag=-1;res=c-'0';
while((c=getchar())>='0'&&c<='9')res=res*10+c-'0';res*=flag;
}
int main(){
	int n,m;
	read(n),read(m);
	if(n==m)puts("Yes");
	else puts("No");
	return 0;
}
