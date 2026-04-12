#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
inline void write(int a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a){
	write(a); puts("");
}
inline int read()//不管是正负数，都可以 
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
const int N=100005;
struct point{
	int x,y,num;
}a[N],e[N<<1];
inline bool cmp1(point a,point b){
	return a.x<b.x;
}
inline bool cmp2(point a,point b){
	return a.y<b.y;
}
inline bool cmp3(point a,point b){
	return a.num<b.num;
}
long long ans;
int n,have,m,father[N];
inline int getfather(int x){
	return x==father[x]?x:father[x]=getfather(father[x]);
}
int main(){
	n=read(); 
	for(int i=1;i<=n;i++){a[i].x=read(); a[i].y=read(); father[i]=a[i].num=i;}
	sort(&a[1],&a[n+1],cmp1); 
	for(int i=1;i<n;i++){
		e[++m].x=a[i].num; e[m].y=a[i+1].num; e[m].num=min(a[i+1].x-a[i].x,abs(a[i+1].y-a[i].y));
	}
	sort(&a[1],&a[n+1],cmp2);
	for(int i=1;i<n;i++){
		e[++m].x=a[i].num; e[m].y=a[i+1].num; e[m].num=min(a[i+1].y-a[i].y,abs(a[i+1].x-a[i].x));
	}
	sort(&e[1],&e[m+1],cmp3);
	for(int i=1;have<n-1;i++){
		int t1=getfather(e[i].x),t2=getfather(e[i].y);
		if(t1!=t2){
			father[t1]=t2;
			have++; ans+=e[i].num;
		}
	}
	writeln(ans);
}