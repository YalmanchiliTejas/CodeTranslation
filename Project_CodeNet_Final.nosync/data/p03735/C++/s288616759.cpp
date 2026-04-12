#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e9,mod=1e9+7;
typedef long long ll;
int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') f=(c=='-')?-1:1,c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}
struct node {
	int x,y,id;
} a[1000001];
multiset<int> red;
multiset<int> blue;
bool cmp(const node & a , const node & b ){
	return a.x<b.x;	
}
int calc(){
	return (*red.rbegin()-*red.begin())*(*blue.rbegin()-*blue.begin());
}
main() {
	int n=read();
	for(int i=1; i<=n; i++) {
		a[i].x=read(),a[i].y=read();
		if(a[i].x>a[i].y) swap(a[i].x,a[i].y);
		red.insert(a[i].x);
		blue.insert(a[i].y);
	}
	sort(a+1,a+1+n,cmp);
	int minx=calc();
	for(int i=1;i<=n;i++){
		int x=a[i].x,y=a[i].y;
		red.erase(red.find(a[i].x));
		blue.erase(blue.find(a[i].y));
		red.insert(a[i].y),blue.insert(a[i].x);
		minx=min(minx,calc());
	}
	printf("%lld",minx);
}