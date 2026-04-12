#include<bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
inline ll read(){
	ll sum=0;int k=1;
	char c=getchar();
	for(;c<'0' || c>'9';c=getchar()) if(c=='-') k=-1;
	for(;c>='0' && c<='9';c=getchar()) sum=sum*10+c-48;
	return sum*k;
}
int n;
const int N=2e5+10,inf=2e9;
struct Ball{
	int x,y;
	bool operator<(const Ball &qwq)const{
		return x<qwq.x;
	}
}a[N];
ll ans;
multiset<int> R,W;
inline ll calc(){
	return 1ll*(*(--R.end())-*R.begin())*(*(--W.end())-*W.begin()); 
}
int main(){
	n=read();
	for(re int i=1;i<=n;++i){
		int x=read(),y=read();
		if(x>y) swap(x,y);
		a[i]=(Ball){x,y};
		R.insert(x);W.insert(y);
	}
	ans=calc();
	sort(a+1,a+n+1);
	for(re int i=1;i<=n;++i){
		int x=a[i].x,y=a[i].y;
		R.erase(R.find(x));W.insert(x);
		W.erase(W.find(y));R.insert(y);
		ans=min(ans,calc());
	}
	cout<<ans;
	return 0;
}
/*
3 815 6901 3839 178 199 10007 

*/