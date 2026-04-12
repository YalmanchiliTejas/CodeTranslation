#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 200005
using namespace std;
typedef long long ll;
int n;
struct data{
	int a,id,b;
}d[maxn];
bool cmp(const data &x,const data &y){
	return x.a < y.a;
}
bool cmp2(const data &x,const data &y){
	return x.id < y.id;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i].a);
		d[i].id = i;
	}
	sort(d+1,d+n+1,cmp);
	int m = n>>1;
	for(int i=1;i<=m;i++) d[i].b = d[m+1].a;
	for(int i=m+1;i<=n;i++){
		d[i].b = d[m].a;
	}
	sort(d+1,d+n+1,cmp2);
	for(int i=1;i<=n;i++){
		printf("%d\n",d[i].b);
	}
	return 0;
}
