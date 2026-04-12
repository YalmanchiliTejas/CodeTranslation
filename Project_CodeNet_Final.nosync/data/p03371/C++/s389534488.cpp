#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

void read(int &x){
	x=0;int f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c-'0');c=getchar();}
	x*=f;
}

int main(){
	int ans=0;
	int x,y,a,b,c;
	read(a);read(b);read(c);read(x);read(y);
	if(a+b<c*2){
		ans=x*a+y*b;
	}
	else {
			ans=min(x,y)*2*c;
		if(x!=y){
			if(x>y){
				if(a*abs(y-x)<c*2*abs(x-y)) ans+=a*abs(y-x);
				else ans+=abs(x-y)*c*2;
			}
			else {
				if(b*abs(x-y)<c*2*abs(x-y)) ans+=b*abs(x-y);
				else ans+=abs(x-y)*c*2;
			}
		}
	}
	printf("%d",ans);
}