#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
const ll inf=1e18;
const int N=1e5+3;
struct oy{
	int x,y,id;
}a[N],b[N];
struct dio{
	int u,v,w;
}e[N<<1];
bool cmp1(oy a,oy b){return a.x<b.x;}
bool cmp2(oy a,oy b){return a.y<b.y;}
bool cmp3(dio a,dio b){return a.w<b.w;}
int pre[N],n,cnt;
int find(int x){
	return pre[x]==x?x:pre[x]=find(pre[x]);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) pre[i]=i;
    for(int i=1;i<=n;i++){
    	cin>>a[i].x>>a[i].y;
    	a[i].id=b[i].id=i;
    	b[i].x=a[i].x;b[i].y=a[i].y;
    }
    sort(a+1,a+1+n,cmp1);
    sort(b+1,b+1+n,cmp2);
    for(int i=2;i<=n;i++){
    	e[cnt].u=a[i-1].id;
    	e[cnt].v=a[i].id;
    	e[cnt].w=a[i].x-a[i-1].x;
    	cnt++;
    }
    for(int i=2;i<=n;i++){
    	e[cnt].u=b[i-1].id;
    	e[cnt].v=b[i].id;
    	e[cnt].w=b[i].y-b[i-1].y;
    	cnt++;
    }
    int num=0;
    ll ans=0;
    sort(e,e+cnt,cmp3);
    for(int i=0;i<cnt;i++){
    	int x=find(e[i].u),y=find(e[i].v);
    	if(x!=y){
    		pre[x]=y;
    		ans+=e[i].w;
    		num++;
    	}
    	if(num==n-1) break;
    }
    cout<<ans<<endl;
    return 0;
}