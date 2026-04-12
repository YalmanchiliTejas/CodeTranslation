#include <bits/stdc++.h>
using namespace std;

using ll=long long;
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
	scanf("%lld",&i);
	return i;
}

void printSpace(){
	printf(" ");
}

void printEoln(){
	printf("\n");
}

void print(int x,int suc=1){
	printf("%lld",x);
	if(suc==1)
		printEoln();
	if(suc==2)
		printSpace();
}

string readString(){
	static char buf[3341919];
	scanf("%s",buf);
	return string(buf);
}

char* readCharArray(){
	static char buf[3341919];
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

const int Size=10010;
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
	REP(i,30){
		if((p>>i)&1)
			mult(s,a);
		mult(a,a);
	}
	return s;
}

ll modInv(ll a){
	return modPow(a,mod-2);
}

int fact[Size],factInv[Size];
void Init(){
	fact[0]=1;
	FOR(i,1,Size){
		fact[i]=fact[i-1];
		mult(fact[i],i);
	}
	factInv[Size-1]=modInv(fact[Size-1]);
	for(int i=Size-2;i>=0;i--)
		factInv[i]=factInv[i+1]*(i+1)%mod;
}
int comb(int a,int b){
	return fact[a]*factInv[b]%mod*factInv[a-b]%mod;
}

#undef int

void inplace_fft(int buf[],int k,int prim){
	int n=1<<k;
	{
		int j=0;
		FOR(i,1,n){
			for(int t=1<<(k-1);!((j^=t)&t);t>>=1);
			if(i<j)swap(buf[i],buf[j]);
		}
	}
	REP(l,k){
		int w=modPow(prim,(mod-1)/(1<<(l+1)));
		for(int i=0;i<n;i+=(1<<(l+1))){
			int a=1;
			REP(j,1<<l){
				int p=buf[i+j],q=ll(buf[i+(1<<l)+j])*a%mod;
				buf[i+j]=p+q;if(buf[i+j]>=mod)buf[i+j]-=mod;
				buf[i+(1<<l)+j]=p-q;if(buf[i+(1<<l)+j]<0)buf[i+(1<<l)+j]+=mod;
				a=ll(a)*w%mod;
			}
		}
	}
}

#define int ll

signed bufA[1<<15],bufB[1<<15];
vi convolution(vi const& a,vi const& b){
	int n=a.size(),k=0;
	while((1<<k++)<n);
	memset(bufA,0,sizeof(bufA));
	copy(ALL(a),bufA);
	inplace_fft(bufA,k,3);
	memset(bufB,0,sizeof(bufB));
	copy(ALL(b),bufB);
	inplace_fft(bufB,k,3);
	REP(i,1<<k)mult(bufA[i],bufB[i]);
	inplace_fft(bufA,k,modInv(3));
	int invN=modInv(1<<k);
	REP(i,n)mult(bufA[i],invN);
	return vi(bufA,bufA+n);
}

signed main(){
	Init();
	
	int x=0,y=0;
	{
		string a=readString(),b=readString();
		int n=a.size();
		REP(i,n)if(a[i]=='1'){
			if(b[i]=='0')x++;
			else y++;
		}
	}
	
	vi dp(y+1,0),w(y+1);
	dp[0]=1;
	REP(i,y+1)w[i]=factInv[i+1];
	{
		int p=x;
		while(p){
			if(p&1)
				dp=convolution(dp,w);
			w=convolution(w,w);
			p>>=1;
		}
	}
	
	int ans=0;
	REP(i,y+1)
		add(ans,dp[i]);
	
	cout<<ans*fact[x]%mod*fact[y]%mod*fact[x+y]%mod<<endl;
}