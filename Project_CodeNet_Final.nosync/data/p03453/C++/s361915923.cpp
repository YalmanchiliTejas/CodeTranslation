#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
#define inf 1000000007000000007
typedef long long ll;
using namespace std;
#define N 100010
typedef pair<ll,ll> P;
typedef pair<ll,pair<ll,ll> >PP;
ll n,m,s,t;
vector<pair<ll,ll> >v[N];

priority_queue<PP,vector<PP>,greater<PP> >Q;
ll d[N][2],cnt[N][2];
void Dijkstra(ll start,ll flag){
	lol(i,n)d[i][flag]=inf,cnt[i][flag]=0;
	Q.push(make_pair(0,make_pair(start,-1)));
	while(!Q.empty()){
		ll a=Q.top().first,b=Q.top().second.first;
		ll from=Q.top().second.second;
		Q.pop();
		if(d[b][flag]<a)continue;
		if(d[b][flag]==a){
			cnt[b][flag]+=cnt[from][flag];
			cnt[b][flag]%=mod;
			continue;
		}
		d[b][flag]=a;
		if(from==-1)cnt[b][flag]=1;
		else cnt[b][flag]=cnt[from][flag];
		lol(i,v[b].size()){
			Q.push(make_pair(v[b][i].first+a,make_pair(v[b][i].second,b)));
		}
	}
}

int main(){
	cin>>n>>m>>s>>t;s--,t--;
	lol(i,m){
		ll a,b,c;cin>>a>>b>>c;a--,b--;
		v[a].push_back(make_pair(c,b));
		v[b].push_back(make_pair(c,a));
	}
	Dijkstra(t,1);
	Dijkstra(s,0);
	ll k=d[t][0];
	
	ll sum=0;
	lol(i,n){
		if(d[i][0]*2>k)continue;
		if(d[i][0]*2==k){
			ll tmp=cnt[i][0]*cnt[i][1]%mod;
			sum+=tmp*tmp;sum%=mod;
			continue;
		}
		//d[i][0]*2<kが成り立っている
		lol(j,v[i].size()){
			ll to=v[i][j].second,cost=v[i][j].first;
			if(cost+d[i][0]==d[to][0]&&d[to][0]*2>k&&cost+d[i][0]+d[to][1]==k){
				//cout<<"#"<<i+1<<" "<<to+1<<endl;
				ll tmp=cnt[i][0]*cnt[to][1]%mod;
				sum+=tmp*tmp;sum%=mod;
			}
		}
	}
	ll ans=(cnt[s][1]*cnt[t][0]-sum)%mod;
	cout<<ans<<endl;
	return 0;
}
