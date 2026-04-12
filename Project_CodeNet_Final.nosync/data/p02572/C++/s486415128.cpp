#include<bits/stdc++.h>
#define ll long long int
#define ul unsigned long long int
#define all(arr) arr.begin(), arr.end()
#define va vector<long long int> a 
#define vb vector<long long int> b
#define debug() for(ll l=0;l<50;l++){}
const ll M = 1e9+7;
const ll inf = 1e18+5;
const ll val = 10000020;
const ll INF=INT_MAX;
using namespace std;
#define fast cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
ll bs(ll arr[], ll l, ll r, ll x){
	ll mid=0;
    if (r >= l){
		if (arr[mid] == x) return mid; 
        if (arr[mid] > x) return bs(arr, l, mid - 1, x); 
        return bs(arr, mid + 1, r, x); 
    }
    return -1;
}
ll cs(vector<ll> &a,ll x){
	return upper_bound(all(a),x)-a.begin();
}
ll power(ll x,ul y,ll p){
	ll res = 1;
	x = x % p;
	if(x == 0) return 0;
	while (y > 0){
		if (y & 1) res = (res*x) % p;
		y = y>>1;
		x = (x*x) % p;
		}
	return res;
}
ll arr[500000],st[500000];
void buildtree(int si,int ss,int se){
	if(ss==se){
		st[si]=arr[ss];
		return;
	}
	int mid=ss+(se-ss)/2;
	buildtree(2*si,ss,mid);
	buildtree(2*si+1,mid+1,se);
	st[si]=min(st[2*si],st[2*si+1]);
}
int query(int si,int ss,int se,int qs,int qe){
	if(qs>se || qe<ss) //completely outside
		return INF;
	if(ss>=qs && se<=qe)
		return st[si];
	int mid=ss+(se-ss)/2;
	int l=query(2*si,ss,mid,qs,qe);
	int r=query(2*si+1,mid+1,se,qs,qe);
	return min(l,r);
}
void update(int si,int ss,int se,int qi){
	if(ss==se){
		st[si]=arr[ss];
		return;
	}
	int mid=ss+(se-ss)/2;
	if(qi<=mid) update(2*si,ss,mid,qi);
	else update(2*si+1,mid+1,se,qi);
	st[si]=min(st[2*si],st[2*si+1]);
}
ll mm(ll a,ll b,ll mod){ 
    ll res = 0;
    a %= mod; 
    while(b){
        if (b & 1) res = (res + a) % mod; 
        a = (2 * a) % mod; 
        b >>= 1; // b = b / 2 
    } 
    return res; 
} 

void DFS_ITR(vector<vector<ll>>& adj,ll src,vector<ll>& a,vector<ll>& f,vector<ll>& d,ll day,vector<bool>& visited){
	vector<ll>s;
    s.push_back(src);
    vector<ll>s2;
    visited[src]=true;
    while(s.size()>0){
		ll u=s[s.size()-1];
        s.pop_back();
        for(auto c:adj[u]){
            if(!visited[c]){
                ll eat=min(a[src-1],f[c-1]);
                f[c-1]-=eat;
                if(f[c-1]==0 && d[c]==-1) d[c]=day;
                s.push_back(c);
                s2.push_back(c);
                visited[c]=true;
			}
		}
	}
    for(auto i:s2) visited[i]=false;
}
ll nCr(ll n, ll r){
    return (n*(n-1)*(n-2))/6;
}

void solve(){
	ll n;
	cin>>n;
	ll a[n],b[n]={0},sum=0;
	b[n-1]=a[n-1];
	for(ll i=0;i<n;i++){ cin>>a[i]; b[i]=a[i];}
	for(ll i=n-2;i>=0;i--) b[i]=(b[i+1]+b[i])%M;
	for(ll i=0;i<n-1;i++){
		sum=(sum+mm(a[i],b[i+1],M))%M;
	}
	cout<<sum<<"\n";
}
int main(){
	fast;
    ll t=1;
    //cin>>t;
    while(t--) solve();
	return 0;
}

