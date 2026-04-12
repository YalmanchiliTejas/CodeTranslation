#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)

struct city{
		int x,y,i;
		city(){};
		city(int x_,int y_,int i_){
			x=x_,y=y_,i=i_;
		};

};

struct edge{
			int cst,e1,e2;
		edge(){};
		edge(int cst_,int e1_,int e2_){
			cst=cst_,e1=e1_,e2=e2_;
		};
		bool operator<(const edge& o)const{return cst>o.cst;}			
};

struct unionFind{
	size_t n;
	vector<int> pr;
	unionFind(size_t n_){
		n=n_;
		pr.resize(n,-1);
	};
	int root(int a){
		if(pr[a]==-1)return a;
		else return pr[a]=root(pr[a]);
	}
	void unify(int a,int b){
		a=root(a);b=root(b);
		if(a==b)return;
		pr[b]=a;
	}
	bool same(int a,int b){return root(a)==root(b);}
};


signed main(){
	size_t n;cin>>n;
	vector<city>c(n);
	rep(i,n){cin>>c[i].x>>c[i].y;c[i].i=i;}
	priority_queue<edge> pq;
	sort(begin(c),end(c),[&](const city a,const city b){return a.x<b.x;});
//	for(auto&& u:c)cerr<<u.i<<" ";
//	cerr<<endl;
	rep(i,n-1)pq.push(edge(c[i+1].x-c[i].x,c[i].i,c[i+1].i));

	sort(begin(c),end(c),[&](const city a,const city b){return a.y<b.y;});
//	for(auto&& u:c)cerr<<u.i<<" ";
//	cerr<<endl;

	rep(i,n-1)pq.push(edge(c[i+1].y-c[i].y,c[i].i,c[i+1].i));

	unionFind uf(n);
	int cnt=0,sm=0;
	while(!pq.empty()){
	edge x=pq.top();pq.pop();
//	cerr<<x.cst<<" "<<x.e1<<" "<<x.e2<<endl;
      if(uf.same(x.e1,x.e2))continue;
		uf.unify(x.e1,x.e2);
		cnt++;sm+=x.cst;	
		if(cnt==n-1)break;
	}	
	cout<<sm<<endl;

	
	
	 
}