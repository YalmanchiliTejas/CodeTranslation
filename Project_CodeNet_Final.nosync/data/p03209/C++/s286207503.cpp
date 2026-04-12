#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
typedef long long LL;

LL b[51];
LL p[51];
LL dfs(int N,LL X){
	//cout<<N<<" "<<X<<endl;
	if(b[N]+p[N]<=X)return p[N];
	if(N==0)return 0;
	if(X<=0)return 0;
	if(X==b[N-1]+p[N-1]+2)return p[N-1]+1;
	if(X<=b[N-1]+p[N-1]+1)return dfs(N-1,X-1);
	return p[N-1]+1+dfs(N-1,X-(b[N-1]+p[N-1]+2));
}

int main(){
	int N;
	LL X;
	cin>>N>>X;
	b[0]=0;
	p[0]=1;
	REP(i,N+1){
		if(i==0)continue;
		b[i]=b[i-1]*2+2;
		p[i]=p[i-1]*2+1;
		//cout<<i<<" "<<b[i]<<" "<<p[i]<<endl;
	}
	
	LL ans=dfs(N,X);
	
	cout<<ans<<endl;
}