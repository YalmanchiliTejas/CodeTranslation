#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a),i##end=(b);i<=i##end;i++)
#define temT template<typename T>
using namespace std;
typedef long long ll;
const int N=int(1e5)+10;

int fp[N],x,m,i,l,r; ll n,res,cur;

ll SB(){
	FOR(i,0,N-10) if(fp[i]==1) x=i;
	FOR(i,1,(int)n) res+=x,x=1ll*x*x%m;
	return res;
}

int main(){
	cin>>n>>x>>m;
	for(i=1;!fp[x];x=1ll*x*x%m,i++) fp[x]=i;
	if(fp[x]>n) return cout<<SB(),0;
	FOR(j,1,N-10) if(fp[j] && fp[j]<fp[x]) res+=j;
	l=i-fp[x]; r=(n-fp[x]+1)%l;
	FOR(j,1,N-10) if(fp[j]>=fp[x]){
		if(fp[j]-fp[x]<r) res+=j;
		cur+=j;
	}
	res+=cur*((n-fp[x]+1)/l);
	return cout<<res,0;
}