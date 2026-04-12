/*
  mail: mleautomaton@foxmail.com
  author: MLEAutoMaton
  This Code is made by MLEAutoMaton
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define ll long long
#define re register
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
inline int gi()
{
	int f=1,sum=0;char ch=getchar();
	while(ch>'9' || ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){sum=(sum<<3)+(sum<<1)+ch-'0';ch=getchar();}
	return f*sum;
}
const int N=500010;
struct node{int x,y;bool operator<(const node &b)const{return x<b.x;}}p[N];
int n;
multiset<int>r,b;
int main()
{
	n=gi();
	for(int i=1;i<=n;i++)
	{
		int x=gi(),y=gi();if(x>y)swap(x,y);
		p[i]=(node){x,y};r.insert(x);b.insert(y);
	}
	sort(p+1,p+n+1);ll ans=0;
	ans=1ll*(*(--r.end())-*r.begin())*(*(--b.end())-*b.begin());
	for(int i=1;i<=n;i++)
	{
		r.erase(r.find(p[i].x));
		b.erase(b.find(p[i].y));
		r.insert(p[i].y);
		b.insert(p[i].x);
		ans=min(ans,1ll*(*(--r.end())-*r.begin())*(*(--b.end())-*b.begin()));
	}
	printf("%lld\n",ans);
	return 0;
}
