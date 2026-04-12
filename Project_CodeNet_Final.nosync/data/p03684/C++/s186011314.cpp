#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> P1;

#define fr first
#define sc second
#define mp1(a,b,c) P1(a,P(b,c))
#define SORT(vec) sort(vec.begin(),vec.end())
#define UNIQ(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
#define ZAAT(vec) SORT(vec),UNIQ(vec)

template <int N = 100010>
struct UF{
	int par[N],r[N];
	UF(){
		for(int i = 0 ; i < N ; i ++){
			par[i] = i;
			r[i] = 0;
		}
	}
	void init(){
		for(int i = 0 ; i < N ; i ++){
			par[i] = i;
			r[i] = 0;
		}
	}
	int find(int x){
		if(par[x] == x)return x;
		return par[x] = find(par[x]);
	}
	bool same(int x,int y){
		return find(x) == find(y);
	}
	void unit(int x,int y){
		if(same(x,y))return;
		x = find(x);
		y = find(y);
		if(r[x] < r[y]){
			par[x] = y;
		}
		else {
			par[y] = x;
			if(r[x] == r[y]){
				r[x] ++;
			}
		}
	}
};

ll N;
vector<P1> ed;
ll mst(){
	UF<300010> uf;
	SORT(ed);
	ll ret=0;
	for(P1 p: ed){
		if(uf.same(p.sc.fr,p.sc.sc)){}
		else {
			uf.unit(p.sc.fr,p.sc.sc);
			ret+=p.fr;
		}
	}
	return ret;
}

int main(){
	static ll n;
	static ll x[100010],y[100010];
	scanf("%lld",&n);
	for(int i=0;i<n;i++){
		scanf("%lld%lld",&x[i],&y[i]);
	}
	vector<ll> X,Y;
	for(int i=0;i<n;i++){
		X.push_back(x[i]);
		Y.push_back(y[i]);
	}
	ZAAT(X);
	ZAAT(Y);
	int N=n+X.size()+Y.size();
	for(int i=0;i<n;i++){
		int xx=lower_bound(X.begin(),X.end(),x[i])-X.begin();
		int yy=lower_bound(Y.begin(),Y.end(),y[i])-Y.begin();
		ed.push_back(mp1(0,i,n+xx));
		ed.push_back(mp1(0,i,n+X.size()+yy));
	}
	for(int i=0;i+1<X.size();i++){
		ed.push_back(mp1(X[i+1]-X[i],n+i,n+i+1));
	}
	for(int i=0;i+1<Y.size();i++){
		ed.push_back(mp1(Y[i+1]-Y[i],n+X.size()+i,n+X.size()+i+1));
	}
	cout<<mst()<<endl;
}