#include<bits/stdc++.h>
using namespace std;
template<typename T>void operator<<(vector<T>&vt,const T t){vt.push_back(t);}
template<typename T,typename U>istream&operator>>(istream&s,pair<T,U>&p){return s>>p.first>>p.second;}
template<typename T,typename U>ostream&operator<<(ostream&s,const pair<T,U>p){return s<<p.first<<" "<<p.second;}
#define all(x) x.begin(),x.end()
typedef pair<int,int>pii;

int p[100000];
int uni(int i){
	return p[i]!=i?p[i]=uni(p[i]):i;
}

pair<int,pii>dist(pii v,pii u){
	return {abs(v.first-u.first),{v.second,u.second}};
}

int N;
vector<pii>xi,yi;
vector<pair<int,pii>>E;

main(){
	cin>>N;
	for(int i=0;i<N;++i){
		int x,y;
		cin>>x>>y;
		xi<<(pii){x,i};
		yi<<(pii){y,i};
		p[i]=i;
	}
	sort(all(xi));
	sort(all(yi));
	for(int i=0;i<N-1;++i){
		E<<dist(xi[i],xi[i+1]);
		E<<dist(yi[i],yi[i+1]);
	}
	sort(all(E));
	long long a=0;
	for(auto e:E){
		int x=uni(e.second.first);
		int y=uni(e.second.second);
		if(x!=y){
			p[x]=y;
			a+=e.first;
		}
	}
	cout<<a;
}
