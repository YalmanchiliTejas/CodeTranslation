#include<bits/stdc++.h>
#define gc getchar
#define rint register int
#define rep(i,u,z) for(rint i=u;i<=z;++i)
#define reb(i,u,z) for(rint i=u;i>=z;--i)
#define inf 0x7fffffff

using namespace std;
typedef long long ll;

inline int readint(){
	int rt=0,sign=1;
	char ch=gc();
	while(ch<'0'||ch>'9'){
		if(ch=='-')sign=-1;
	    ch=gc();
	}
	while(ch>='0'&&ch<='9'){
		rt=(rt<<3)+(rt<<1)+(ch&15);
		ch=gc();
	}
	return rt*sign;
}
int main(){
	int x=readint();
	if(x==5||x==7||x==3)puts("YES");
	else puts("NO");
	return 0;
}