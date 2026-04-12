#include<bits/stdc++.h>
typedef long long i64;
const int N=4e5+7;
int n,x[N],gmn,gmx;
i64 ans=1ll<<61;
void mins(i64&a,i64 b){if(a>b)a=b;}
void mins(int&a,int b){if(a>b)a=b;}
void maxs(int&a,int b){if(a<b)a=b;}
void cal1(){
	int mn1,mx1,mn2,mx2;
	mn1=x[gmn];
	mx1=x[gmx^1];
	mn2=x[gmn^1];
	mx2=x[gmx];
	for(int i=0;i<n;i+=2){
		if(i/2==gmn/2||i/2==gmx/2)continue;
		maxs(mx1,x[i]);
		mins(mn2,x[i+1]);
	}
	mins(ans,i64(mx1-mn1)*(mx2-mn2));
}
struct pos{
	int x,y;
	bool operator<(const pos&w)const{return x<w.x;}
}ps[N];
int pp=0;
void cal2(){
	int mn1,mx1,mn2,mx2;
	mn1=x[gmn];
	mx1=x[gmx];
	mn2=x[gmn^1];
	mx2=x[gmx^1];
	if(mn2>mx2)std::swap(mn2,mx2);
//	printf("(%d %d)(%d %d)\n",mn1,mx1,mn2,mx2);
	for(int i=0;i<n;i+=2){
		if(i/2==gmn/2||i/2==gmx/2)continue;
		ps[pp++]=(pos){x[i],x[i+1]};
	}
	ps[pp++]=(pos){mn2,mn2};
	ps[pp++]=(pos){mx2,mx2};
	std::sort(ps,ps+pp);
	maxs(mx2,ps[pp-1].x);
	for(int i=0;i<pp;++i){
//		printf(" (%d %d)(%d %d)\n",mn1,mx1,std::min(ps[i].x,mn2),mx2);
		mins(ans,i64(mx1-mn1)*(mx2-std::min(ps[i].x,mn2)));
//		printf("(%d  %d)\n",ps[i].x,ps[i].y);
		maxs(mx2,ps[i].y);
		mins(mn2,ps[i].y);
	}
	mins(ans,i64(mx1-mn1)*(mx2-mn2));
}
int main(){
	scanf("%d",&n);
	n*=2;
	gmn=0,gmx=0;
	for(int i=0;i<n;++i)scanf("%d",x+i);
	for(int i=0;i<n;i+=2)if(x[i]>x[i+1])std::swap(x[i],x[i+1]); 
	for(int i=0;i<n;++i){
		if(x[i]<x[gmn])gmn=i;
		if(x[i]>x[gmx])gmx=i;
	}
	cal1();
	if(gmn^gmx^1)cal2();
	printf("%lld\n",ans);
	return 0;
}