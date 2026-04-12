#include<bits/stdc++.h>
using namespace std;
int n;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int main(){
	n=read();
  if(n>=30) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
	return 0;
}
