bool debug=false;
#include <queue>
#include <algorithm>
#include <vector>
#include <utility>
#include <stdio.h>
using namespace std;
#define F first
#define S second
#define PB push_back
const int N=1e5+10;
struct seg_tree{
	vector<int> v,p,cnt,have;
	void init(int n,int l,int r){
		if(v.size()<=n){
			v.resize(n+1);
			cnt.resize(n+1);
		}
		if(l<r){
			int mid=(l+r)>>1;
			init(n*2+1,l,mid);
			init(n*2+2,mid+1,r);
		}
		return ;
	}
	void init(int n){
		p.resize(n);
		for(int i=0;i<n;i++)p[i]=i;
		have.resize(n);
		init(0,0,n-1);
		return ;
	}
	int find(int n){return p[n]==n?n:p[n]=find(p[n]);}
	void push_up(int n){
		cnt[n]=cnt[n*2+1]+cnt[n*2+2];
		if(v[n*2+1]==-1||v[n*2+2]==-1)v[n]=-1;
		else if(find(v[n*2+1])==find(v[n*2+2]))v[n]=find(v[n*2+1]);
		else if(v[n*2+1]==0)v[n]=find(v[n*2+2]);
		else if(v[n*2+2]==0)v[n]=find(v[n*2+1]);
		else v[n]=-1;
	}
	void fix(int n,int l,int r,int pos,int x){
		if(l==r){
			if(x==-1){
				have[pos]--;
				if(have[pos]==0)cnt[n]=v[n]=0;
			}
			else {
				if(have[pos]==0)cnt[n]++;
				v[n]=x;
				have[pos]++;
			}
		}
		else{
			int mid=(l+r)>>1;
			if(pos>mid)fix(n*2+2,mid+1,r,pos,x);
			else fix(n*2+1,l,mid,pos,x);
			push_up(n);
		}
		return ;
	}
	void merge(int n){
		//if(debug)printf("merge(%d)\n",n);
		if(v[n*2+1]==-1)merge(n*2+1);
		if(v[n*2+2]==-1)merge(n*2+2);
		if(v[n*2+1]==0)v[n]=find(v[n*2+2]);
		else if(v[n*2+2]==0)v[n]=find(v[n*2+1]);
		else v[n]=p[find(v[n*2+1])]=find(v[n*2+2]);
		return ;
	}
	pair<int,int> ask(int n,int l,int r,int L,int R){
		//if(debug)printf("ask(%d,%d,%d,%d,%d)\n",n,l,r,L,R);
		if(L<=l&&r<=R){
			if(v[n]==-1)merge(n);
			return {cnt[n],v[n]};
		}
		else if(l>R||L>r)return {0,0};
		else{
			int mid=(l+r)>>1;
			pair<int,int> left=ask(n*2+1,l,mid,L,R),right=ask(n*2+2,mid+1,r,L,R),ans;
			ans.F=left.F+right.F;
			if(left.S==0)ans.S=right.S;
			else if(right.S==0)ans.S=left.S;
			else ans.S=p[find(left.S)]=find(right.S);
			return ans;
		}
	}
	int ask(int L,int R){
		return ask(0,0,(int)p.size()-1,L,R).F;
	}
};
bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
	return a.S<b.S;
}
int main(){
	int temp,w,h,n,x1,now=1,x2,y1,y2;
	long long int line=0,point=0,comp=0;
	vector<int> x,y;
	vector<pair<pair<int,int>,int>> hor,ver;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> in,out;
	seg_tree seg;
	scanf("%d%d%d",&w,&h,&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		x.PB(x1);x.PB(x2);
		y.PB(y1);y.PB(y2);
		if(x1==x2)hor.PB({{y1,y2},x1});
		else ver.PB({{x1,x2},y1});
	}
	hor.PB({{0,h},0});
	hor.PB({{0,h},w});
	ver.PB({{0,w},0});
	ver.PB({{0,w},h});
	x.PB(0);
	x.PB(w);
	y.PB(0);
	y.PB(h);
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	x.resize(unique(x.begin(),x.end())-x.begin());
	y.resize(unique(y.begin(),y.end())-y.begin());
	for(int i=0;i<hor.size();i++)hor[i]={{lower_bound(y.begin(),y.end(),hor[i].F.F)-y.begin(),lower_bound(y.begin(),y.end(),hor[i].F.S)-y.begin()},lower_bound(x.begin(),x.end(),hor[i].S)-x.begin()};
	for(int i=0;i<ver.size();i++)ver[i]={{lower_bound(x.begin(),x.end(),ver[i].F.F)-x.begin(),lower_bound(x.begin(),x.end(),ver[i].F.S)-x.begin()},lower_bound(y.begin(),y.end(),ver[i].S)-y.begin()};
	for(int i=0;i<hor.size();i++){
		in.push({hor[i].F.F,hor[i].S});
		out.push({hor[i].F.S,hor[i].S});
		point+=2;
		line++;
	}
	sort(ver.begin(),ver.end(),cmp);
	n+=10;
	n<<=1;
	seg.init(n);
	for(int i=0;i<ver.size();i++){
		if(debug)printf("ver[%d]=(%d,%d,%d)\n",i,ver[i].F.F,ver[i].F.S,ver[i].S);
		while(!in.empty()){
			if(in.top().F<=ver[i].S){
				seg.fix(0,0,n-1,in.top().S,now++);
				in.pop();
			}
			else break;
		}
		while(!out.empty()){
			if(out.top().F<ver[i].S){
				seg.fix(0,0,n-1,out.top().S,-1);
				out.pop();
			}
			else break;
		}
		temp=seg.ask(ver[i].F.F,ver[i].F.S);
		point+=temp+2;
		line+=(temp<<1)+1;
		if(temp==0)comp++;
		if(debug)printf("%d::temp=%d point=%d line=%d comp=%d\n",i,temp,point,line,comp);
		if(debug)printf("now=%d\n",now);
		if(0&&debug){
			printf("p::");
			for(int i=1;i<now;i++)printf(" %d",seg.p[i]);
			printf("\n");
		}
	}
	while(!in.empty()){
		in.pop();
		comp++;
	}
	for(int i=1;i<now;i++)if(seg.p[i]==i)comp++;
	printf("%lld\n",line-point+comp);
	if(debug)printf("line=%d point=%d comp=%d\n",line,point,comp);
}

