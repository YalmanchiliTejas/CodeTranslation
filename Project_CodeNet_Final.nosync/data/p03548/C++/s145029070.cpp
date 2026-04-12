#include <bits/stdc++.h>
#define ll long long
using namespace std;
void put(int x){
	if(x<0) {
		putchar('-');
		x*=-1;
	}
	if(x==0) {
		putchar('0');
	}
	int num=0;
	char c[15];
	while(x) {
		c[++num]=(x%10)+48;
		x/=10;
	}
	while(num) {
		putchar(c[num--]);
	}
	putchar('\n');
}
inline void in(int &x){
	char ch=getchar();
	int flag=1;
	while(!(ch>='0'&&ch<='9')) {
		if(ch=='-')
			flag*=-1;
		ch=getchar();
	}
	x=ch-'0';
	ch=getchar();
	while(ch>='0'&&ch<='9') {
		x=((x<<3)+(x<<1))+ch-'0';
		ch=getchar();
	}
	x*=flag;
}
int a,b,c; 
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	in(a);in(b);in(c);
	printf("%d\n",(a-c)/(b+c));
	return 0;
}
