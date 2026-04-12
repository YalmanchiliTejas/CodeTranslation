#include<bits/stdc++.h>
#define mod 1000000007
#define MAX 1111111
#define ll long long int
#define ld long double
#define inf ((ll)INT_MAX)*1000
using namespace std;
bool s[MAX];
ll f[MAX];
ll fibo[MAX];
ll fibonacci(ll x){
    fibo[1]=fibo[2]=1;
    if (x<MAX && !fibo[x])
        return fibo[x];
    if (x<MAX)
        return fibo[x]=(fibonacci(x-1)+fibonacci(x-2))%mod;
    return fibo[x]=(fibonacci(x-1)+fibonacci(x-2))%mod;
}
ll mul(ll a,ll b,ll m){
    ll result=0;
    a%=m;
    while(b){
        if (b&1)
            result=(result+a)%m;
        a=(2*a)%m;
        b>>=1;
    }
    return result;
}
ll power(ll b,ll e,ll m){
    ll result=1;
    b%=m;
    while(e){
        if (e&1)
            result=mul(result,b,m);
        e>>=1;
        b=mul(b,b,m);
    }
    return result;
}
bool func1(pair<ll,ll> x,pair<ll,ll> y){
    if (x.first==y.first)
        return x.second<y.second;
    return x.first<y.first;
}
bool func2(pair<ll,ll> x,pair<ll,ll> y){
    if (x.second==y.second)
        return x.first<y.first;
    return x.second<y.second;
}
bool dfunc(ll a,ll b){
    return a>b;
}
ll fact(ll x){
    if (x<=1)
        return f[x]=1;
    if (f[x])
        return f[x];
    if (x<MAX)
        return f[x]=x*fact(x-1);
    return x*fact(x-1);
}
void seive(){
    for (ll i=2;i<MAX;i++)
        if (!s[i])
            for (ll j=i*i;j<MAX;j+=i)
                s[j]=true;
}
vector<vector<ll>> adj(MAX);
bool visited[MAX];
queue<ll> q;
vector<ll> side(MAX,-1);
ll cover1,cover2;
bool isbi=true;
void dfs(ll n){
    visited[n]=true;
    for (ll i:adj[n])
        if (!visited[i])
            dfs(i);
}
void bibfs(ll n){
    ll s;
    for (s=1;s<=n;s++)
        if (side[s]==-1){
            q.push(s);
            side[s]=0;
            cover1++;
            while(!q.empty()){
                ll temp=q.front();
                q.pop();
                for (ll j:adj[temp])
                    if (side[j]==-1){
                        q.push(j);
                        side[j]=side[temp]^1;
                        if (!side[j])
                            cover1++;
                        else
                            cover2++;
                    }
                    else
                        isbi&=(side[j]!=side[temp]);
            }
        }
}
void bfs(ll n){
    q.push(n);
    while(!q.empty()){
        ll temp=q.front();
        q.pop();
        visited[temp]=true;
        for (ll j:adj[temp])
            if (!visited[j])
                q.push(j);
    }
}
vector<vector<pair<ll,ll>>> adj1(MAX);
void dk(ll n,ll s,vector<ll> &d,vector<ll> &p){
    ll i,j,v;
    d[s]=0;
    vector<bool> u(n+5,false);
    for (i=1;i<=n;i++){
        v=-1;
        for (j=1;j<=n;j++)
            if (!u[j] && (v==-1 || d[j]<d[v]))
                v=j;
        u[v]=true;
        if (d[v]==((ll)INT_MAX)*1000)
            break;
        for (pair<ll,ll> temp:adj1[v])
            if (d[v]+temp.second<d[temp.first]){
                d[temp.first]=d[v]+temp.second;
                p[temp.first]=v;
            }
    }
}
ll sakamoto(ll d,ll m,ll y){ 
    ll t[]={0,3,2,5,0,3,5,1,4,6,2,4};  
    if (m<3) 
        y-=1; 
    return ((y+y/4-y/100+y/400+t[m-1]+d)%7); 
}
ll seg1[MAX];
vector<ll> a;
void build(ll left,ll right,ll index){
    if (left==right){
        seg1[index]=a[left];
        return;
    }
    ll mid=(left+right)/2;
    build(left,mid,2*index);
    build(mid+1,right,2*index+1);
    seg1[index]=seg1[2*index]+seg1[2*index+1];
}
ll query(ll left,ll right,ll lindex,ll rindex,ll index){
    if (right<lindex || rindex<left)
        return 0;
    if (left<=lindex && right>=rindex)
        return seg1[index];
    return query(left,right,lindex,(lindex+rindex)/2,2*index)+query(left,right,(lindex+rindex)/2+1,rindex,2*index+1);
}
bool check(ll n,ll a,ll d,ll s){
	ll x=power(a,d,n);
	if (x==1 || x==n-1)
		return false;
	for (ll i=1;i<s;i++){
		x=mul(x,x,n);
		if (x==n-1)
			return false;
	}
	return true;
}
bool miller(ll n,ll iter){
    srand(time(0));
	if (n<4)
		return n==2 || n==3;
	ll d=n-1;
	ll s=0;
	while(!(d&1)){
		d>>=1;
		s++;
	}
	for (ll i=1;i<=iter;i++){
        ll a=2+rand()%(n-3);
		if (check(n,a,d,s))
			return false;
	}
	return true;
}
ll arr[MAX],dp[MAX],prefix[MAX];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--){
        ll n,i;
        cin>>n;
        for (i=1;i<=n;i++)
            cin>>arr[i];
        prefix[1]=arr[1];
        for (i=3;i<=n;i++)
            prefix[i]=prefix[i-2]+arr[i];
        for (i=2;i<=n;i++)
            if (i&1)
                dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
            else{
                dp[i]=dp[i-2]+arr[i];
                dp[i]=max(dp[i],prefix[i-1]);
            }
        cout<<dp[n]<<endl;
    }
    return 0;
}