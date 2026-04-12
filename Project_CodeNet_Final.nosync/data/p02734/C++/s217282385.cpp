#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

const int MOD=998244353;
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;

int n,s;
int a[5000];

ll ans=0;

void solve(int l,int r){
	if(r<=l)return;
	if(r-l==1){
		if(a[l]==s)ans++;
		return;
	}
	int md=(l+r)/2;
	vector<ll>dpl(3001),dpr(3001);
	vector<ll>L(3001),R(3001);
	dpl[0]=1;
	dpr[0]=1;
	assert(l<md&&md<r);
	for(int i=md-1;i>=l;i--){
		for(int j=3000-a[i];j>=0;j--){
			(dpl[j+a[i]]+=dpl[j])%=MOD;
		}
		rep(j,3001)(L[j]+=dpl[j])%=MOD;
	}
	for(int i=md;i<r;i++){
		for(int j=3000-a[i];j>=0;j--){
			(dpr[j+a[i]]+=dpr[j])%=MOD;
		}
		rep(j,3001)(R[j]+=dpr[j])%=MOD;
	}
	rep(j,s+1){
		(ans+=L[j]*R[s-j])%=MOD;
	}
	solve(l,md);
	solve(md,r);
}

int main(){
	cin>>n>>s;
	rep(i,n)scanf("%d",&a[i]);
	solve(0,n);
	cout<<ans<<endl;
}