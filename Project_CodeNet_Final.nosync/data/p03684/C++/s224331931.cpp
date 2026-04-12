#include<bits/stdc++.h>
using namespace std;
int n,le;
struct pnt{
	int x,y,id;
} a[111111];
pair<int,pair<int,int> > e[1111111];
int ace[111111];
bool cmp_x(pnt x,pnt y){
	return x.x < y.x;
}
bool cmp_y(pnt x,pnt y){
	return x.y < y.y;
}
int dis(pnt x,pnt y){
	return min((int)labs(x.x-y.x),(int)labs(x.y-y.y));
}
int ancestor(int x){
	return x-ace[x]?ace[x]=ancestor(ace[x]):x;
}
int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].id=i;
	}
	sort(a,a+n,cmp_x);
	for(int i=1; i<n; i++)
		e[le++]=make_pair(dis(a[i],a[i-1]),make_pair(a[i].id,a[i-1].id));
	sort(a,a+n,cmp_y);
	for(int i=1; i<n; i++)
		e[le++]=make_pair(dis(a[i],a[i-1]),make_pair(a[i].id,a[i-1].id));
	sort(e,e+le);
	for(int i=0; i<n; i++)
		ace[i] = i;
	int res = 0;
	for(int i=0; i<le; i++){
		int x=e[i].second.first,y=e[i].second.second;
		if(ancestor(x) != ancestor(y)){
			res += e[i].first;
			ace[ancestor(x)] = ancestor(y);
		}
	}
	printf("%d\n",res);
	return 0;
}
