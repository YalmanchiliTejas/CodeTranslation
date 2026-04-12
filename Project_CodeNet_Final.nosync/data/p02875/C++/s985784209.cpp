#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=10000005,mod=998244353;
int fac[N],rev[N],n,ans,res;

int power(int x,int p){
	int res=1;
	for(;p;p>>=1,x=(ll)x*x%mod)
		if(p&1) res=(ll)res*x%mod;
	return res;
}
int mul(int x,int y){
	return (ll)x*y%mod;
}
void add(int &x,int y){
	x=(x+y>=mod?x+y-mod:x+y);
}

int C(int n,int m){
	return m<0||n<m?0:mul(fac[n],mul(rev[m],rev[n-m]));
}
void init(int n){
	fac[0]=1;
	rep(i,1,n) fac[i]=mul(fac[i-1],i);
	rev[n]=power(fac[n],mod-2);
	per(i,n,1) rev[i-1]=mul(rev[i],i);
}

int main(){
	read(n);
	init(n);

	ans=res=1;
	per(c,n-1,0){
		res=mul(res,2);
		if(c<n/2){
			add(res,mod-mul(2,C(n-c-1,(n-2*c)/2-1)));
			//cout<<n<<" "<<c<<"  "<<n-c<<"   "<<res<<endl;
		}
		add(ans,mul(C(n,c),res));
	}
	cout<<ans<<endl;

    return 0;
}