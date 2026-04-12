#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	short f=1;x=0;char c=getchar();
	while(!isdigit(c)){ if(c=='-')f=-1;c=getchar(); }
	while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
	x*=f;
}
int main(){
	int a,b,c;
	read(a),read(b),read(c);
	cout<<(a-c)/(b+c)<<endl;
	return 0;
}
