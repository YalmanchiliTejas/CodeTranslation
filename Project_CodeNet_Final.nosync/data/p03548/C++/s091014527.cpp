#include<bits/stdc++.h>
#define INF 9999999;
using namespace std;
inline int read() {
	char c = getchar(); int x = 0, f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}
int n,m,z;
int main()
{
	n=read();
	m=read();
	z=read();
	n-=z;
	m+=z;
	cout<<n/m<<'\n';
	return 0;
}
