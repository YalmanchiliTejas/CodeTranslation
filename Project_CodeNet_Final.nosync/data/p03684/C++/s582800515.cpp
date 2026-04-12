//#include<stdio.h>
//#include<stdlib.h>
#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define MEM(x) memset(x,0,sizeof(x))
#define N 200005
#define pi 3.14159265359
using namespace std;
typedef long long LL;
struct town{
	int x,y,i;
};
bool cmp(const town &a,const town &b){
	return a.x>b.x;
}
bool cmp1(const town &a,const town &b){
	return a.y>b.y;
}
struct road{
	int x,y,len;
};
bool operator<(const road &a,const road &b){
	return a.len<b.len; 
} 
int f[100005];
int Find(int a){
	if(f[a]==a)
	return a;
	return f[a]=Find(f[a]);
}
	road r[200005];
		town t[100005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		t[i].x=a;
		t[i].y=b;
		t[i].i=i;//=mp(a,b);
	}
	sort(t,t+n,cmp);
	int index=0;
	for(int i=1;i<n;i++){
		r[index].x=t[i].i;
		r[index].y=t[i-1].i;
		r[index].len=t[i-1].x-t[i].x;
		index++;
	}
	sort(t,t+n,cmp1);
	for(int i=1;i<n;i++){
		r[index].x=t[i].i;
		r[index].y=t[i-1].i;
		r[index].len=t[i-1].y-t[i].y;
		index++;
	}
	sort(r,r+index);
	for(int i=0;i<n;i++)
	f[i]=i;
	LL ans=0;
	for(int i=0;i<index;i++){
		int a=r[i].x;
		int b=r[i].y;
		int fa=Find(a);
		int fb=Find(b);
		if(fa!=fb){
		//	printf("%d %d %d\n",a,b,r[i].len);
			f[fa]=fb;
			ans+=r[i].len;
		}
	}
	printf("%lld\n",ans);
}