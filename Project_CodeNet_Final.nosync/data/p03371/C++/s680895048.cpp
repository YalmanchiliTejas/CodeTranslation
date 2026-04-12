#include<bits/stdc++.h>

using namespace std;

inline int read(){
	char ch=getchar();int x=0,f=1;
    while(ch<'0' || ch>'9') {
       if(ch=='-') f=-1;
	  	  ch=getchar();
	}
    while(ch<='9' && ch>='0') {
	   x=x*10+ch-'0';
	   ch=getchar();
	}
    return x*f;
}

int main(){
	int sum=0X7fffffff;
	int a=read(),b=read(),c=read();
	c*=2;
	int x=read(),y=read();
	if(x>y){
		swap(x,y);
		swap(a,b);
	}
	sum=min(a*x+b*y,sum);
	sum=min(c*x+(y-x)*b,sum);
	sum=min(c*x+(y-x)*c,sum);
	cout<<sum;
	return 0;
}
