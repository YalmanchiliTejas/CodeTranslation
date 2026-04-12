#include <bits/stdc++.h>
using namespace std;

using ll=int64_t;
//#define int ll

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
	#ifdef int
	scanf("%" SCNd64,&i);
	#else
	scanf("%d",&i);
	#endif
	return i;
}

void printSpace(){
	printf(" ");
}

void printEoln(){
	printf("\n");
}

void print(int x,int suc=1){
	#ifdef int
	printf("%" PRId64,x);
	#else
	printf("%d",x);
	#endif
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
	if(b<a)
		a=b;
}

template<class T>
T Sq(const T& t){
	return t*t;
}

#define CAPITAL
void Yes(bool ex=true){
	#ifdef CAPITAL
	cout<<"YES"<<endl;
	#else
	cout<<"Yes"<<endl;
	#endif
	if(ex)exit(0);
}
void No(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<endl;
	#else
	cout<<"No"<<endl;
	#endif
	if(ex)exit(0);
}

#ifdef int
const int inf=LLONG_MAX/3;
#else
const int inf=INT_MAX/2-100;
#endif

template<ll base>
struct FastModuloTransform{
	ll modPow(ll a,ll b){
		ll res=1;
		REP(i,32){
			if((b>>i)&1)
				res=res*a%base;
			a=a*a%base;
		}
		return res;
	}

	ll modInv(ll a){
		return modPow(a,base-2);
	}

	inline ll modPlus(ll a,ll b){
		ll res=a+b;
		return res<base?res:res-base;
	}

	inline ll modMinus(ll a,ll b){
		ll res=a-b;
		return res>=0?res:res+base;
	}

	inline void modMul(ll& a,ll b){
		a=a*b%base;
	}

	void fmt(ll* data,int n,ll root){
		for(int i=0,j=1;j<n-1;j++){
			for(int k=n>>1;k>(i^=k);k>>=1);
			if(i<j)
				swap(data[i],data[j]);
		}
		for(int b=1;b<=n/2;b*=2){
			ll w=modPow(root,(base-1)/(b*2));
			for(int i=0;i<n;i+=b*2){
				ll p=1;
				for(int j=i;j<i+b;j++){
					modMul(data[j+b],p);
					ll t=data[j];
					data[j]=modPlus(t,data[j+b]);
					data[j+b]=modMinus(t,data[j+b]);
					modMul(p,w);
				}
			}
		}
	}

	void convolution(ll* x,ll* y,int n,bool yReuse){
		int s=1;
		while(s<n)s*=2;
		s*=2;
		const ll root=3;
		fmt(x,s,root);
		if(!yReuse)fmt(y,s,root);
		REP(i,s)
			modMul(x[i],y[i]);
		fmt(x,s,modInv(root));
		ll t=modInv(s);
		REP(i,s)
			modMul(x[i],t);
	}
};

const int mod=998244353;
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
void InitFact(){
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
	return ll(fact[n])*factInv[n-k]%mod*factInv[k]%mod;
}
int Binom(int a,int b){
	return ll(fact[a+b])*factInv[a]%mod*factInv[b]%mod;
}

ll dp[2][1<<14],buf[1<<14];

signed main(){
	InitFact();
	int n=read(),m=read();
	int cur=0;
	dp[cur][0]=1;
	FastModuloTransform<mod> fmt;
	FOR(i,1,n+1)buf[i]=factInv[i+2];
	REP(_,m){
		int nx=cur^1;
		ZERO(dp[nx]);
		REP(i,n+1){
			dp[nx][i]=dp[cur][i];
			mult(dp[nx][i],1+(i+1)*i/2);
		}
		REP(i,n+1)mult(dp[cur][i],factInv[i]);
		fmt.convolution(dp[cur],buf,n+1,_);
		REP(i,n+1){
			mult(dp[cur][i],fact[i+2]);
			add(dp[nx][i],dp[cur][i]);
		}
		cur=nx;
	}
	int ans=0;
	REP(i,n+1){
		mult(dp[cur][i],Choose(n,i));
		add(ans,dp[cur][i]);
	}
	cout<<ans<<endl;
}
