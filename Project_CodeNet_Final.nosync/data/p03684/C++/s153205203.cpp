#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P2;
const int inf=1000000000;
int pa[100001]={};
int ra[100001]={};

int find(int xx){
	if(pa[xx]==xx)return xx;
	return pa[xx]=find(pa[xx]);
}
int same(int xx,int yy){
	return 	find(xx)==find(yy);
}
void unite(int xx,int yy){
	xx=find(xx);
	yy=find(yy);
	if(ra[xx]<ra[yy]){
		pa[xx]=yy;
	}else{
		pa[yy]=xx;
		if(ra[xx]==ra[yy])ra[xx]++;
	}
	return;
}
int main() {
	int n;

	cin>>n;
	P x[100001]={};
	P y[100001]={};
	for(int i=0;i<n+1;++i)pa[i]=i;


	for(int i=0;i<n;++i){
		int x1,y1;
		cin>>x1>>y1;
		x[i]=P(x1,i+1);
		y[i]=P(y1,i+1);
	}
	sort(x,x+n);
	sort(y,y+n);
	P2 d[200001]={};
	for(int i=0;i<n-1;++i){
		d[i]=P2(abs(x[i].first-x[i+1].first),P(x[i].second,x[i+1].second));
		d[i+n-1]=P2(abs(y[i].first-y[i+1].first),P(y[i].second,y[i+1].second));
	}
	sort(d,d+2*n-2);
	ll t=0;
	for(int i=0;i<2*n-2;i++){
		P2 p1=d[i];
		int cost=p1.first;
		P p3=p1.second;
		int x1=p3.first;
		int y1=p3.second;
		if(!same(x1,y1)){
			t+=(ll)cost;
			unite(x1,y1);
		}
	}
	cout<<t<<endl;
	return 0;
}
