#include<bits/stdc++.h>
using namespace std;
inline int read(void){
	int num = 0, f = 1;
	char ch;
	while(!isdigit(ch=getchar())) if(ch == '-') f = -1;
	while(isdigit(ch)) num = num*10 + ch-'0', ch = getchar();
	return num * f;
}
int main()
{
	int x = read();
	if(x >= 30) puts("Yes");
	else puts("No");
	return 0;
}