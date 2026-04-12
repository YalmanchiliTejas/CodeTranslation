#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=a;i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(a>b)a=b;}

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}

template<class t> void mkuni(vc<t>&v){
	sort(all(v));
	v.erase(unique(all(v)),v.ed);
}

ll read(){ll i;cin>>i;return i;}

using ld=long double;
using cm=complex<ld>;
#define x real()
#define y imag()
const ld eps=1e-7;
const ld PI=acos(ld(-1));
int sgn(ld a){return a<-eps?-1:(a>eps?1:0);}
auto cmcmp=[](const cm&a,const cm&b){
	if(sgn(a.x-b.x))return a.x<b.x;
	else return sgn(a.y-b.y)<0;
};
ld dot(cm a,cm b){return a.x*b.x+a.y*b.y;}
ld crs(cm a,cm b){return a.x*b.y-a.y*b.x;}
int ccw(cm a,cm b){return sgn(crs(a,b));}
int ccw(cm a,cm b,cm c){return ccw(b-a,c-a);}
//AOJ1183
int qeq(ld a,ld b,ld c,ld&d,ld&e){
	ld f=b*b-4*a*c;
	if(sgn(f)<0)return 0;
	ld g=sqrt(max(f,ld(0)));
	d=(-b+g)/(2*a);
	e=(-b-g)/(2*a);
	return sgn(f)+1;
}
//(-2)[a,-1](0)[b,1](2)
int bet(cm a,cm b,cm c){
	cm d=b-a;
	ld e=dot(d,c-a);
	if(sgn(e)<=0)return sgn(e)-1;
	return sgn(e-norm(d))+1;
}
ld tri2(cm a,cm b,cm c){
	return crs(b-a,c-a);
}
//AOJ0153
//0-no,1-edge,2-in
int cont(cm a,cm b,cm c,cm d){
	if(ccw(a,b,c)==-1)
		swap(b,c);
	return min({ccw(a,b,d),ccw(b,c,d),ccw(c,a,d)})+1;
}
//AOJ1183
//arg between ab
//assume given lengths are valid
ld arg(ld a,ld b,ld c){
	return acos(min(max((a*a+b*b-c*c)/(2*a*b),ld(-1)),ld(1)));
}

using ln=pair<cm,cm>;
cm dir(ln a){return a.b-a.a;}
cm eval(ln a,ld b){return a.a+dir(a)*b;}
cm proj(ln a,cm b){
	cm c=dir(a);
	return a.a+c*dot(c,b-a.a)/norm(c);
}
cm refl(ln a,cm b){
	return ld(2)*proj(a,b)-b;
}
//AOJ0153
ld dsp(ln a,cm b){
	cm c=proj(a,b);
	if(abs(bet(a.a,a.b,c))<=1)return abs(b-c);
	return min(abs(b-a.a),abs(b-a.b));
}
int ccw(ln a,cm b){return ccw(a.a,a.b,b);}
//AOJ1157
//0-no,1-yes(endpoint),2-yes(innner)
int iss(ln a,ln b){
	int c=ccw(a.a,a.b,b.a)*ccw(a.a,a.b,b.b);
	int d=ccw(b.a,b.b,a.a)*ccw(b.a,b.b,a.b);
	int e=max(c,d);
	if(e)return 1-e;
	int f=bet(a.a,a.b,b.a),g=bet(a.a,a.b,b.b);
	if(max(f,g)==-2||min(f,g)==2)return 0;
	return 1;
}
//AOJ1157
ld dss(ln a,ln b){
	if(iss(a,b))return 0;
	return min({dsp(a,b.a),dsp(a,b.b),dsp(b,a.a),dsp(b,a.b)});
}

template<class E,class D=ll>
vc<D> dijkstra(const vvc<E>& g,int s){
	const int n=g.size();
	using P=pair<D,int>;
	priority_queue<P,vc<P>,greater<P>> pq;
	vc<D> dist(n,1e9);
	const auto ar=[&](int v,D d){
		if(dist[v]>d){
			dist[v]=d;
			pq.push(P(d,v));
		}
	};
	ar(s,0);
	while(pq.size()){
		D d;
		int v;
		tie(d,v)=pq.top();pq.pop();
		for(auto e:g[v])
			ar(e.to,d+e.cost);
	}
	return dist;
}


signed main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(20);
	
	while(1){
		int n=read(),m=read()-1,l=read()-1;
		if(n==0)break;
		vc<ln> w;
		rep(i,n){
			ld s,t,a,r;
			cin>>s>>t>>a>>r;
			vc<cm> z;
			rep(k,5)
				z.pb(cm(s,t)+polar(r,PI/2+a/180*PI+k*PI*0.8));
			rep(k,5)
				w.eb(z[k],z[(k+1)%5]);
		}
		
		struct E{int to;ld cost;};
		vvc<E> g(n*5+2);
		g[n*5].pb(E{m*5,0});
		g[l*5].pb(E{n*5+1,0});
		rep(i,n*5)rep(j,n*5)
			g[i].pb(E{j,dss(w[i],w[j])});
		
		cout<<dijkstra<E,ld>(g,n*5)[n*5+1]<<endl;
	}
}

