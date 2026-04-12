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

const int mod=1000000007;
int fact[1111111];
int inv[1111111];

int mpow(int n,int m){
	int ret=1;
	while(m){
		if(m&1)ret=ret*n%mod;
		n=n*n%mod;
		m>>=1;
	}
	return ret;
}

int binom(int n,int k){
	return fact[n]*inv[k]%mod*inv[n-k]%mod;
}

inline void add(int &a,int b){
	a+=b;
	if(a>=mod)a-=mod;
}

int N,M;
string S;

int dp[222222];
int sum[222222];

signed main(){
	fact[0]=1;
	for(int i=1;i<1111111;i++)fact[i]=fact[i-1]*i%mod;
	inv[1111111-1]=mpow(fact[1111111],mod-2);
	for(int i=1111111-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;


	cin>>N>>M;
	cin>>S;

	if(S[0]=='B'){
		rep(i,M){
			if(S[i]=='R')S[i]='B';
			else S[i]='R';
		}
	}

	while(S.size()&&S.back()=='R')S.pop_back();

	if(S.size()==0){
		int ans=0;
		int a=1,b=0;
		rep(i,N){
			int aa=(a+b)%mod;
			int bb=a;
			a=aa;b=bb;
		}
		add(ans,a);

		a=0;b=1;
		rep(i,N){
			int aa=(a+b)%mod;
			int bb=a;
			a=aa;b=bb;
		}
		add(ans,b);
		cout<<ans<<endl;
		return 0;
	}

	if(N%2){
		cout<<0<<endl;
		return 0;
	}

	int ma=1001001001;
	int cur=0;
	while(cur<S.size()){
		int nex=cur;
		while(nex<S.size()&&S[cur]==S[nex])nex++;
		if(S[cur]=='R'){
			int l=nex-cur;
			if(cur==0){
				if(l%2)chmin(ma,l);
				else chmin(ma,l+1);
			}
			else{
				if(l%2)chmin(ma,l);
			}
		}
		cur=nex;
	}

    ma=(ma+1)/2;
    N/=2;

    dp[0]=sum[0]=1;

    int ans=0;
    for(int i=1;i<=N;i++){
        dp[i]=sum[i-1];
        if(i>ma)dp[i]=(dp[i]-sum[i-ma-1]+mod)%mod;
        sum[i]=(sum[i-1]+dp[i])%mod;
    }

    for(int i=1;i<=ma;i++){
        add(ans,dp[N-i]*i%mod*2%mod);
    }
    cout<<ans<<endl;
	return 0;
}
