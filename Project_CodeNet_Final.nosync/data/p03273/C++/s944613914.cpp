#include <cstdio>

inline int readin(){
	int x=0,c;
	for (;(c=getchar())<'0'||c>'9';);
	for (;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+c-48;
	return x;
}

char s[233][233];
bool p[233],q[233];

int main(){
	int h=readin(),w=readin();
	for (int i=1;i<=h;i++) scanf("%s",s[i]+1);
	for (int i=1;i<=h;i++){
		for (int j=1;j<=w;j++) if (s[i][j]!='.') p[i]=1;
	}
	for (int i=1;i<=w;i++){
		for (int j=1;j<=h;j++) if (s[j][i]!='.') q[i]=1;
	}
	for (int i=1;i<=h;p[i]?puts(""):0,i++)
		for (int j=1;j<=w;j++) if (p[i]&&q[j]) putchar(s[i][j]);
}