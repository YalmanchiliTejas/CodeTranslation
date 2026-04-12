#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cmath>
#include<cstring>
#include<climits>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define LL long long
//#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
//char buf[(1 << 21) + 1], *p1 = buf, *p2 = buf;
inline int read() {
	bool f=0;int x=0;char c=getchar();
	while(c<'0'||'9'<c){if(c==EOF)exit(0);if(c=='-')f=1;c=getchar();}
	while('0'<=c&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return !f?x:-x;
}
#define MAXN 100
#define INF 0x3f3f3f3f
char S[MAXN+5];
int main(){
	scanf("%s",S);
	int len=strlen(S),k=read();
	if(k==1){
		printf("%d\n",S[0]-'0'+(len-1)*9);
		return 0;
	}
	if(k==2){
		int ans=(len-1)*(len-2)/2*9*9+(S[0]-'0'-1)*(len-1)*9;
		for(int i=1;i<len;i++)
			if(S[i]-'0'){
				ans+=(len-1-i)*9+S[i]-'0';
				break;
			}
		printf("%d\n",ans);
		return 0;
	}
	int ans=(len-1)*(len-2)*(len-3)/6*9*9*9+(S[0]-'0'-1)*(len-1)*(len-2)/2*9*9;
	
	for(int i=1;i<len;i++)
		if(S[i]-'0'){
			ans+=(len-1-i)*(len-2-i)/2*9*9+(S[i]-'0'-1)*(len-1-i)*9;
			for(int j=i+1;j<len;j++)
				if(S[j]-'0'){
					ans+=(len-1-j)*9+S[j]-'0';
					break;
				}
			break;
		}
	printf("%d\n",ans);
	return 0;
}
