#include <cstdio>
#include <algorithm>
using namespace std;
int read () {
	int k=0;
	char c=getchar();
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9') {k=k*10+c-'0';c=getchar();}
	return k;
}
int main () {
	int x,y,z,i=0,s=0;
	x=read();y=read();z=read();
	for (;s+z<=x;s=s+z+y,i++);
	printf ("%d",i-1);
}