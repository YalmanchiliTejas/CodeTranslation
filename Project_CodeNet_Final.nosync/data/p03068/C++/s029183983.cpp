#include <bits/stdc++.h>
using namespace std;
#define ll long long
inline int read() {
	int f=1,x=0;char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) {x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
int main() {
	int n,k;
	char str[20];
	n=read();
	scanf("%s",str);
	k=read();
	for(int i=0;i<n;i++) {
		if(str[i]!=str[k-1]) str[i]='*';
	}
	printf("%s",str);
	return 0;
}
