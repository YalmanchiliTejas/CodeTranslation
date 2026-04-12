//satyaki3794
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define MOD (1000000007LL)
#define LEFT(n) (2*(n))
#define RIGHT(n) (2*(n)+1)
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
 
ll pwr(ll base, ll p, ll mod){
ll ans = 1;while(p){if(p&1)ans=(ans*base)%mod;base=(base*base)%mod;p/=2;}return ans;
}
 
 
ll gcd(ll a, ll b){
    if(b == 0)  return a;
    return gcd(b, a%b);
}
 
 
int n, color[100005];
set<int> adj[100005], orig[100005];
bool removed[100005];
 
 
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    cin>>n;
    if(n == 1){
    	cout<<"First";
    	return 0;
    }
 
 
    int e = n-1;
    while(e--){
 
    	int a, b;
    	cin>>a>>b;
    	adj[a].insert(b);
    	adj[b].insert(a);
    }
 
    priority_queue<ii> pq;
    for(int i=1;i<=n;i++){
    	pq.push(ii(-(int)adj[i].size(), i));
    	color[i] = -1;
    }
 
    while(!pq.empty()){
 
    	int v = pq.top().ss;
    	int deg = -pq.top().ff;
    	pq.pop();
 
// cout<<"popped "<<v<<" "<<deg<<endl; 
 
    	if(color[v] != -1){
    		continue;
    	}
 
// cout<<"retained "<<v<<" "<<deg<<endl;
 
 		assert(deg <= 1);

    	if(deg == 0){
    		color[v] = 0;
    		cout<<"First";
    		return 0;
    	}
 
    	if(deg == 1){
    		int vv = (*adj[v].begin());
    		color[vv] = 0;
    		color[v] = 1;
    		for(auto it : adj[vv]){
    			adj[it].erase(vv);
    			pq.push(ii(-(int)adj[it].size(), it));
    		}
    		adj[v].clear();
    		adj[vv].clear();
    		continue;
    	}
 
    	// assert(0);
    }
 
// for(int i=1;i<=n;i++)	cout<<color[i]<<" ";cout<<endl;
    cout<<"Second";
    return 0;
}





