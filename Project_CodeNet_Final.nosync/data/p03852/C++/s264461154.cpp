#include<bits/stdc++.h>
#define for(i,a,b) for(int i=a;i<=b;i++)
#define _inline __inline__ __attribute__((always_inline))
using namespace std;
_inline void read(int &x){
	int res=0,f=1;
	char c=getchar();
	if(c=='-') f=-1;
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9'){
		res=res*10+c-'0';
		c=getchar();
	}
	x=res*f;
}
inline void print(int x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
char a;
int main(){
	a=getchar();
	bool f;
	switch(a){
		case 'a':f=true;break;
		case 'e':f=true;break;
		case 'i':f=true;break;
		case 'o':f=true;break;
		case 'u':f=true;break;
		default:f=false;
	}
	if(f) puts("vowel");
	else puts("consonant");
	exit(0);
} 