#include <bits/stdc++.h>

template<class T>inline void readin(T &res) {
	static char ch;T flag = 1;
	while((ch=getchar())<'0'||ch>'9')if(ch=='-')flag=-1;
	res=ch-48;
	while((ch=getchar())>='0'&&ch<='9')res=res*10+ch-48;
	res*=flag;
}

char ss[100];
int main() {
	scanf("%s",ss);
	for( int i = 0; i < strlen(ss)-1; i++ ) if(ss[i]=='A'&&ss[i+1]=='C') {
		printf("Yes\n");
		return 0;
	}
	printf("No\n");
	return 0;
}