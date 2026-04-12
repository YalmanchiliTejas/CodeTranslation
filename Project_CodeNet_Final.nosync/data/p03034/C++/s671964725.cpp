#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
typedef long long LL;
int N;
LL s[100001];

bool check(int a,int b,int k){
	if(a==b)return true;
	if((a-b)==k)return true;
	if(b<=k)return true;
	return false;
}

int main(){
	cin>>N;
	REP(i,N){
		cin>>s[i];
	}
	LL ans=0;
	for(int i=1;i<N;i++){
		LL now=0;
		int a=0;
		int b=N-1;
		REP(j,N+1){
			if(a>N-1||b<0)break;
			now+=(s[a]+s[b]);
			//溺れる判定
			if(check(a,b,i)){
				break;
			}
			ans=max(ans,now);
			a+=i;
			b-=i;
		}
	}
	cout<<ans<<endl;
}