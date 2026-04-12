#include<bits/stdc++.h>
using namespace std;
int f[100005];
int p;
long long cost;

struct edge{
	int x,y,w;
	bool operator < (edge e){
		return w<e.w;
	}
}e[200005];

struct node{
	int id,x,y;
}a[100005];
int N;

bool cmp1(node x,node y){
	return x.x<y.x;
}

bool cmp2(node x,node y){
	return x.y<y.y;
}

bool cmp3(edge x,edge y){
	return x.w<y.w;
}

int getfa(int x){
	if(f[x]==x)return x;
	return f[x]=getfa(f[x]);
}

int main(){
	cin>>N;
	int i,j;
	for(i=1;i<=N;i++)
	f[i]=i;
	
	for(i=1;i<=N;i++){
		cin>>a[i].x>>a[i].y;
		a[i].id=i;
	}
	
	sort(a+1,a+N+1,cmp1);

	
	for(i=1;i<N;i++){
		e[i].x=a[i].id;
		e[i].y=a[i+1].id;
		e[i].w=a[i+1].x-a[i].x;
	}
	
	sort(a+1,a+N+1,cmp2);
	
	for(i=1;i<N;i++){
		e[i+N-1].x=a[i].id;
		e[i+N-1].y=a[i+1].id;
		e[i+N-1].w=a[i+1].y-a[i].y;
	}
	
	sort(e+1,e+2*N-1,cmp3);
	
	for(i=1;i<N;i++){
		while(p<2*N-2){
			p++;
			int fx=getfa(e[p].x),fy=getfa(e[p].y);
			if(fx!=fy){
				f[fy]=fx;
				cost+=e[p].w;
				break;
			}
		}
	}
	cout<<cost<<endl;
	return 0;
} 