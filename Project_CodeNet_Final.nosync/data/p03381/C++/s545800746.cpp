#include<bits/stdc++.h>

#define N 200005

using namespace std;

int n,a[N],b[N],c[N];

template<typename Drake>
void read(Drake &x){
	x=0;char ch=getchar();bool f=1;
	while(!isdigit(ch)){
		if(ch=='-')f^=1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	x*=(2*f-1);
}

template<typename Drake>
void write(Drake x){
	if(x<0){x=-x;putchar('-');}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}

template<typename Drake>
void writeln(Drake x){
	write(x);
	puts("");
}

void init(){
	read(n);
	for(register int i=1;i<=n;i++)
	read(a[i]),b[i]=a[i];
}

int main(){
	init();
	sort(b+1,b+n+1);
	for(register int i=1;i<=n;i++){
		if(a[i]>b[n/2])
		c[i]=b[n/2];
		else c[i]=b[n/2+1];
	}
	for(register int i=1;i<=n;i++){
		writeln(c[i]);
	}
	puts("");
	return 0;
}