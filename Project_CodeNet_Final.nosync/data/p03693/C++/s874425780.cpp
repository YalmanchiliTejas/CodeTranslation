#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0;char ch=getchar();
	while (!isdigit(ch)) ch=getchar();
	while (isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x;
}
int a;
int main(){
	read();a=read()*10+read();
	if (a%4) puts("NO");
	else puts("YES");
	return 0;
}
