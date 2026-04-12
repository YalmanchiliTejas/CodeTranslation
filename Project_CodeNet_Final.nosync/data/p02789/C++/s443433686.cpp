#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

inline int read() {
	int x=0;char c=getchar();
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x;
}

int main() {
	int a=read(),b=read();
	puts(a==b?"Yes":"No"); 
	return 0;
}