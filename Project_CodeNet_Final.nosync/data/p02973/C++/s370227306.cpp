#include<bits/stdc++.h>
using namespace std;
#define pb          push_back
#define m_p			make_pair
#define rep(i,a,b)	for(int i=a;i<b;i++)
#define sz(x)       (int)x.size()
#define f			first
#define debug		cout<<"##########3"<<endl
#define mod			1000000007
#define ll			long long int
#define lMax		LLONG_MAXs
// queue<int> , prefix_sum(a,a+n) , reverse(a,a+n) , priority_queue <int> max heap , priority_queue <int, vector<int>, greater<int> > min heap;
// == precedence gretaer then &
ll n,m;
string s,s1;
priority_queue <long long int> pq;
ll mp[200005];
vector<ll> vec[300005];
vector<pair<int,int> > q;
int par[200005];
int vis[100005];
ll ans[200005];
ll arr[200005];

vector<pair<ll,pair<ll,ll>>> edges;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
    ll i,j,k,c=0,an=0,t,z=0,x=1,y,w=1;
    cin>>n;
    
    rep(i,0,n){
    	cin>>arr[i];
    	ans[n-i-1] = arr[i];
	}
  
  	vector<int> res;
  	res.pb(ans[0]);
  	for(i=1;i<n;i++)
  	{
  		auto it = upper_bound(res.begin(), res.end(), ans[i]);
		if(it==res.end()){
			res.pb(ans[i]);	
		}	
		else
		{
			*it = ans[i];//ok?
		}
	}
  	cout<<res.size();//len of long decrasing was
  
 	return 0;
}