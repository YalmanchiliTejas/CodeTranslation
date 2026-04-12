#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
const int INF=1e9+5;
const int N=2e5+5;
const ll oo=1e18+5;
const ll mod=1e9+7;

int n;
ll a[N];
ll dp[N][3];
bool used[N][3];

ll calc(int pos,int can_go){
	if(pos>=n){
		if(can_go==2) return -oo;
		else return 0;
	}
	if(used[pos][can_go]) return dp[pos][can_go];
	used[pos][can_go]=1;
	dp[pos][can_go]=-oo;
	for(int step=0;step<=can_go&&pos+step<n;++step){
		dp[pos][can_go]=max(dp[pos][can_go],a[pos+step]+calc(pos+step+2,can_go-step));
	}
	return dp[pos][can_go];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(used,0,sizeof(used));
	cin>>n;
	for(int i=0;i<n;++i) cin>>a[i];
	ll ans=calc(0,n%2+1);
	cout<<ans;
	return 0;
}
