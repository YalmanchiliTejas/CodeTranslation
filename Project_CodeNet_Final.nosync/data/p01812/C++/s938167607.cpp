#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a)  (a).begin(),(a).end()
#define pb push_back
#define INF (1e9+1)
//#define INF (1LL<<59)

int main(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> d(m);
	rep(i,m){
		cin>>d[i];
		d[i]--;
	}
	vector<vector<int>> v(n,vector<int>(k));
	rep(i,n){
		rep(j,k){
			cin>>v[i][j];
			v[i][j]--;
		}
	}
	
	int dp[1<<16];
	rep(i,1<<16)dp[i] = INF;
	dp[(1<<m)-1]=0;

	queue<ll> que;
	vector<bool> used(1<<16,false);
	que.push( (1<<m)-1 );
	used[(1<<m)-1]=true;

	while(que.size()){
		int q = que.front();
		que.pop();
		
		rep(i,k){
			int t=0;
			rep(j,m){
				if( q & (1<<j) ){
					int next_room = v[d[j]][i];
					int to = -1;
					rep(l,m){
						if(d[l]==next_room)to = l;
					}
					if(to!=-1)t|=1<<to;
				}
			}
			if(!used[t])que.push(t);
			used[t] = true;
			dp[t] = min(dp[q]+1,dp[t]);
		}
	}
	cout<<dp[0]<<endl;
}