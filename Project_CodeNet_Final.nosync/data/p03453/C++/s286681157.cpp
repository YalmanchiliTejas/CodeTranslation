#include <bits/stdc++.h>
using namespace std;

using ll=int64_t;
#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define REACH cerr<<"reached line "<<__LINE__<<endl
#define DMP(x) cerr<<"line "<<__LINE__<<" "<<#x<<":"<<x<<endl
#define ZERO(x) memset(x,0,sizeof(x))

using pi=pair<int,int>;
using vi=vector<int>;
using ld=long double;

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"[";
	REP(i,(int)v.size()){
		if(i)os<<",";
		os<<v[i];
	}
	os<<"]";
	return os;
}

int read(){
	int i;
	scanf("%" SCNd64,&i);
	return i;
}

void printSpace(){
	printf(" ");
}

void printEoln(){
	printf("\n");
}

void print(int x,int suc=1){
	printf("%" PRId64,x);
	if(suc==1)
		printEoln();
	if(suc==2)
		printSpace();
}

string readString(){
	static char buf[3341000];
	scanf("%s",buf);
	return string(buf);
}

char* readCharArray(){
	static char buf[3341000];
	static int bufUsed=0;
	char* ret=buf+bufUsed;
	scanf("%s",ret);
	bufUsed+=strlen(ret)+1;
	return ret;
}

template<class T,class U>
void chmax(T& a,U b){
	if(a<b)
		a=b;
}

template<class T,class U>
void chmin(T& a,U b){
	if(a>b)
		a=b;
}

template<class T>
T Sq(const T& t){
	return t*t;
}

const int inf=LLONG_MAX/3;

const int Nmax=100010;
vector<pi> g[Nmax];

const int mod=1000000007;
template<class T,class U>
void add(T& a,U b){
	a=((ll)a+b)%mod;
}

template<class T,class U>
void sub(T& a,U b){
	a=((ll)a-b%mod+mod)%mod;
}

template<class T,class U>
void mult(T& a,U b){
	a=((ll)a*b)%mod;
}

ll modPow(ll a,ll p){
	ll s=1;
	while(p){
		if(p&1)mult(s,a);
		mult(a,a);
		p>>=1;
	}
	return s;
}

ll modInv(ll a){
	return modPow(a,mod-2);
}

const int Vmax=1000010;
int fact[Vmax],factInv[Vmax];
void Init(){
	fact[0]=1;
	FOR(i,1,Vmax){
		fact[i]=fact[i-1];
		mult(fact[i],i);
	}
	factInv[Vmax-1]=modInv(fact[Vmax-1]);
	for(int i=Vmax-2;i>=0;i--){
		factInv[i]=factInv[i+1];
		mult(factInv[i],i+1);
	}
}
int Choose(int n,int k){
	return fact[n]*factInv[n-k]%mod*factInv[k]%mod;
}

vector<pi> Wafrelka(int n,int s){
	priority_queue<pi,vector<pi>,greater<pi>>pq;
	vector<pi> dist(n,pi(inf,0));
	const auto Update=[&](int v,int c,int z){
//		cerr<<v<<" "<<c<<" "<<z<<endl;
		if(dist[v].first>c){
			dist[v]=pi(c,0);
			pq.push(pi(c,v));
		}
		if(dist[v].first==c)
			add(dist[v].second,z);
	};
	Update(s,0,1);
	while(!pq.empty()){
		pi w=pq.top();pq.pop();
		int v=w.second,c=w.first;
		if(dist[v].first<c)continue;
		for(auto e:g[v])
			Update(e.first,c+e.second,dist[v].second);
	}
//	cerr<<dist<<endl;
	return dist;
}

signed main(){
	int n=read(),m=read(),s=read()-1,t=read()-1;
	REP(i,m){
		int u=read()-1,v=read()-1,d=read();
		g[u].PB(pi(v,d));
		g[v].PB(pi(u,d));
	}
	vector<pi> a=Wafrelka(n,s),b=Wafrelka(n,t);
	int ans=a[t].second,minDist=a[t].first;
	mult(ans,b[s].second);
	REP(i,n)
		if(a[i].first==b[i].first&&a[i].first+b[i].first==minDist){
			int w=a[i].second;
			mult(w,b[i].second);
			mult(w,w);
			sub(ans,w);
		}
	REP(i,n)
		for(auto e:g[i]){
			int j=e.first,d=e.second;
			if(a[i].first+b[j].first+d==minDist&&a[i].first*2<minDist&&b[j].first*2<minDist){
				int w=a[i].second;
				mult(w,b[j].second);
				mult(w,w);
				sub(ans,w);
			}
		}
	cout<<ans<<endl;
}