#include<bits/stdc++.h>
using namespace std;
#define int long long 
typedef long long ll;
typedef pair<ll,ll>pi;
const int MAXN=200050;
const int MOD=1000000007;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define DEC(i,a,b) for(int i=(a);i>=(b);i--)
#define fst first
#define snd second
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define db(x) cerr<<#x<<" = "<<x<<"\n"
#define LOW(v,x) (lower_bound(all(v),(x))-(v).begin())
#define UP(v,x) (upper_bound(all(v),(x))-(v).begin())

int N,A[MAXN];
int L[MAXN],R[MAXN];
int LL[MAXN][2],RR[MAXN][2];

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>N;
	FOR(i,1,N)cin>>A[i];
	if(N%2==0){
		LL[1][1]=A[1];
		FOR(i,2,N){
			LL[i][i%2]=LL[i-2][i%2]+A[i];
		}
		DEC(i,N,1){
			RR[i][i%2]=RR[i+2][i%2]+A[i];
		}
		int ans=-1e18;
		FOR(i,1,N){
			ans = max(ans,LL[i][i%2]+RR[i+2][(i+2)%2]);
			if (i%2) ans = max(ans,LL[i][i%2]+RR[i+3][(i+3)%2]);
		}
		cout<<ans;
		exit(0);
	}
	int ans=0, cur=0;
	FOR(i,1,N){
		if(i%2==0) cur+=A[i];
	}
	ans=cur;
	FOR(i,1,N){
		if(i%2==0){
			L[i]=L[i-2]+A[i-1];
			L[i]-=A[i];
		}
	}
	DEC(i,N,1){
		if(i%2==0){
			R[i]=R[i+2]+A[i+1];
			R[i]-=A[i];
		}
	}
	FOR(i,2,N-1){
		if(i%2==0) L[i]=max(L[i-2],L[i]);
	}
	DEC(i,N,0){
		if(i%2==0) R[i]=max(R[i+2],R[i]);
	}
	FOR(i,0,N-1){
		if(i%2==0) ans = max(ans, cur+L[i]+R[i+2]);
	}
	cout<<ans;
}
