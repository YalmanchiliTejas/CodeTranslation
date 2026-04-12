#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define f(i,x,n) for(int i=x;i<(int)n;++i)
#define vpii vector<pair<int,int>>
#define vi vector<int>
#define mpii map<pair<int,int>,int>
#define mpivpii map<int,vector<pair<int,int>>>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define sz(x) x.size()
#define mpi map<int,int>
#define vvi vector<vector<int>>
#define vvvi vector<vvi>
ld pie=3.141592653589;
int mod=998244353;

int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};

vi pr;



void solve(){
	int n,x,m; cin>>n>>x>>m;
	int pre=x; int s=x; int vis[m];
	f(i,0,m) vis[i]=-1; vis[x]=0;
	vi ret; ret.pb(x);
	f(i,1,n){
		int nx=pre*pre; nx%=m;
		if(vis[nx]!=-1){
			int before=0,after=0,len=0,len1=0;
			bool pass=0; int id=-1;
			f(j,0,sz(ret)){
				if(ret[j]==nx){
					after+=ret[j];
					++len; id=j;
					pass=1;
					continue;
				}
				if(!pass) {
					before+=ret[j];
					++len1;
				}
				else{
					after+=ret[j];
					++len;
				}
			}
			int ans=before;
			int rem=n-len1; ans+=(rem/len)*after; rem%=len;
			f(j,0,rem){
				ans+=ret[id];	++id;
			}
			cout<<ans<<"\n";
			return ;
		}
		vis[nx]=i; ret.pb(nx);
		s+=nx; pre=nx;
	}
	cout<<s<<"\n";
}


int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
  	int t=1;   //cin>>t;
  	while(t--) solve();
 	return 0;
}