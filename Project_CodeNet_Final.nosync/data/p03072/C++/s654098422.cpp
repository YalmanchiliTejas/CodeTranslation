//minamoto
#include<bits/stdc++.h>
#define R register
#define fp(i,a,b) for(R int i=(a),I=(b)+1;i<I;++i)
#define fd(i,a,b) for(R int i=(a),I=(b)-1;i>I;--i)
#define go(u) for(int i=head[u],v=e[i].v;i;i=e[i].nx,v=e[i].v)
using namespace std;
const int N=25;
int a[N],mx,n,res;
int main(){
	cin>>n;
	fp(i,1,n)cin>>a[i];
	fp(i,1,n){
		res=max(res,a[i]);
		if(res==a[i])++mx;
	}
	cout<<mx<<endl;
	return 0;
} 