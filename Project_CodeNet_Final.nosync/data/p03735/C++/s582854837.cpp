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
#define re register
#define ll long long
inline int gi(){
	int f=1,sum=0;char ch=getchar();
	while(ch>'9' || ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){sum=(sum<<3)+(sum<<1)+ch-'0';ch=getchar();}
	return f*sum;
}
multiset<int>R,B;
struct node
{
	int x,y;
	bool operator<(const node &b)const{return x<b.x;}
}p[200010];
int n;
ll solve()
{
	return 1ll*((*--R.end())-(*R.begin()))*((*--B.end())-(*B.begin()));
}
int main(){
	n=gi();
	for(int i=1;i<=n;i++)
	{
		int x=gi(),y=gi();if(x>y)swap(x,y);
		p[i]=(node){x,y};R.insert(x);B.insert(y);
	}
	sort(p+1,p+n+1);
	ll ans=solve();
	for(int i=1;i<=n;i++)
	{
		R.erase(R.find(p[i].x));B.erase(B.find(p[i].y));
		R.insert(p[i].y);B.insert(p[i].x);
		ans=min(ans,solve());
	}
	printf("%lld\n",ans);
	return 0;
}
