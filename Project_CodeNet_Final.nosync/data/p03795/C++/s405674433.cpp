#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	register short f=1;x=0;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
	x*=f;
}
template<typename T>inline void write(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
template<typename T>inline void writeln(T x){
	write(x),putchar('\n');
}
int main(){
	int n;cin>>n;
	cout<<800*n-200*int(n/15)<<endl;
	return 0;
}
