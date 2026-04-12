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

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=1000005,mod=1e9+7;
int n,m,lim;
char s[N];

void special(int n){
	static int f[N],s[N];
	s[1]=s[0]=f[0]=1;
	rep(i,2,n){
		f[i]=s[i-2];
		s[i]=(s[i-1]+f[i])%mod;
	}
	int ans=1;
	rep(i,2,n)
		ans=(ans+(ll)i*f[n-i])%mod;
	cout<<ans<<endl;
}

void solve(int n,int k){
	static int f[N],s[N];
	s[0]=f[0]=1;
	for(int i=2;i<=n;i+=2){
		f[i]=(s[i-2]+(i>=k+3?mod-s[i-k-3]:0))%mod;
		s[i]=(s[i-2]+f[i])%mod;
	}
	int ans=0;
	for(int i=2;i<=k+1;i+=2)
		ans=(ans+(ll)i*f[n-i])%mod;
	cout<<ans<<endl;
}

int main(){
	read(n),read(m);
	scanf("%s",s+1);
	lim=n-1;
	for(int l=1,r;l<=m;l++)
		if(s[l]==s[1]){
			r=l;
			while(r<m&&s[r+1]==s[l])
				r++;
			if(l==1&&r==m){
				special(n);
				return 0;
			}
			if(l==1){
				if(r%2==0) lim=min(lim,r+1);
				else lim=min(lim,r);
			}
			else if(r!=m&&(r-l)%2==0){
				lim=min(lim,r-l+1);
			}
			l=r;
		}
	solve(n,lim);
	return 0;
}