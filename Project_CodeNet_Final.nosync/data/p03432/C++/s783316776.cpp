#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int mod=998244353;
inline void add(int &a,int b){
    a+=b;
    if(a>=mod)a-=mod;
}
int mpow(int n,int m){
    int ret=1;
    while(m){
        if(m&1)ret=ret*n%mod;
        n=n*n%mod;
        m>>=1;
    }
    return ret;
}
const int FACT_SIZE=1111111;
int fact[FACT_SIZE];
int inv[FACT_SIZE];
struct fact_exec{
    fact_exec(){
        fact[0]=1;
        for(int i=1;i<FACT_SIZE;i++)fact[i]=fact[i-1]*i%mod;
        inv[FACT_SIZE-1]=mpow(fact[FACT_SIZE-1],mod-2);
        for(int i=FACT_SIZE-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
    }
}factexec;
int nCk(int n,int k){
    if(n<0|k<0||k>n)return 0;
    return fact[n]*inv[k]%mod*inv[n-k]%mod;
}
int nPk(int n,int k){
    if(n<0||k<0||k>n)return 0;
    return fact[n]*inv[n-k]%mod;
}


struct NumberTheoreticTransform{
	int mod;
    int root;
	NumberTheoreticTransform(int mod,int root):mod(mod),root(root){}

	int mul(int x,int y){
		return x*y%mod;
	}
	int add(int x,int y){
		return (x+=y)>=mod?x-mod:x;
	}

	int pow(int x,int y){
		int res=1;
		while(y){
			if(y&1)res=mul(res,x);
			x=mul(x,x);
			y>>=1;
		}
		return res;
	}

	int inv(int x){
		return pow(x,mod-2);
	}

	void ntt(vector<int>&f,bool rev=false){
		int n=f.size();
        for(int i=0,j=1;j<n-1;j++){
            for(int k=n>>1;k>(i^=k);k/=2);
            if(i>j)swap(f[i],f[j]);
        }

     	for(int m=2;m<=n;m*=2){
            int wr=pow(root,(mod-1)/m);
            if(rev)wr=inv(wr);
            for(int i=0;i<n;i+=m){
                int w=1;
                for(int j=0;j<m/2;j++){
                    int f0=f[i+j],f1=mul(w,f[i+j+m/2]);
                    f[i+j]=add(f0,f1);
                    f[i+j+m/2]=add(f0,mod-f1);
                    w=mul(w,wr);
                }
            }
        }
        if(rev){
        	int v=inv(n);
        	for(int i=0;i<n;i++)f[i]=mul(f[i],v);
		}
	}
	vector<int>multiply(vector<int>A,vector<int>B){
        int n=1;
        while(n<A.size()+B.size()-1)n<<=1;
        A.resize(n);B.resize(n);
        ntt(A);
        ntt(B);
        for(int i=0;i<n;i++)A[i]=mul(A[i],B[i]);
        ntt(A,true);
        A.resize(A.size()+B.size()-1);
        return A;
    }
}ntt(mod,5);

int N,M;

int dp[210][8010];

signed main(){
    cin>>N>>M;
    rep(i,N+1)dp[0][i]=nCk(N,i);

    for(int i=0;i<M;i++){
        rep(j,N+1)add(dp[i+1][j],dp[i][j]*(j*(j+1)/2+1)%mod);

        vint A(N+1);
        rep(x,N+1)A[x]=dp[i][x]*fact[x]%mod;
        vint B(N+1);
        for(int j=1;j<=N;j++)B[N-j]=inv[j];

        vint C=ntt.multiply(A,B);
        for(int j=1;j<=N;j++)B[N-j]=inv[j+1];
        vint D=ntt.multiply(A,B);
        for(int j=1;j<=N;j++)B[N-j]=inv[j+2];
        vint E=ntt.multiply(A,B);

        rep(j,N+1){
            int tmp=C[N+j]*inv[j]%mod;
            if(j>0)add(tmp,D[N+j]*inv[j-1]%mod*2%mod);
            if(j>1)add(tmp,E[N+j]*inv[j-2]%mod);
            add(dp[i+1][j],tmp);
        }
    }
    cout<<dp[M][0]<<endl;
    return 0;
}
