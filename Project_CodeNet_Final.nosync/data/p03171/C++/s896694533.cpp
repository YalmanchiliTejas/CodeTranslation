#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename x>
using ordered_set = tree<x,null_type,less<x>,rb_tree_tag,tree_order_statistics_node_update>;
#define sorta(a,n) sort(a,a+n)
#define sortad(a,n) sort(a,a+n,greater<__typeof(a[0])>())
#define all(x) (x).begin(),(x).end()
#define ms0(x) memset((x),0,sizeof((x)))
#define ms1(x) memset((x),-1,sizeof((x)))
typedef pair<long long,long long> pi;
#define inarr(arr,n) for(long long i=0;i<n;i++)cin>>arr[i];
#define prinarr(arr) {for(long long x:arr)cout<<x<<" ";} cout<<"\n";
#define cout1(a) cout<<a<<"\n";
#define cout2(a,b) cout<<a<<" "<<b<<"\n";
#define cout3(a,b,c) cout<<a<<" "<<b<<" "<<c<<"\n";
#define setpre(n) cout<<fixed<<setprecision(8)<<n<<"\n";
#define filldp(arr,n,m,k) for(long long i=0;i<n;i++){for(long long j=0;j<m;j++) arr[i][j]=k;}

#define mod 1000000007
#define mod1 998244353


vector<vector<long long>> adj;
vector<long long> dis;
vector<long long> parent;
vector<bool> visited;

void newgr(long long n){
    n+=10;
    adj=vector<vector<long long>>(n);
    dis=vector<long long>(n,0);
    //parent=vector<long long>(n,-1);
    visited=vector<bool>(n,false);
}

void dfs(long long s){
    visited[s]=true;
    for(auto u:adj[s]){
        if(!visited[u]){
            //parent[u]=s;
            dis[u]=dis[s]+1;
            dfs(u);
        }
    }
}

void bfs(long long s){
    queue<long long> q;
    q.push(s);
    visited[s]=true;
    dis[s]=0;
    while(!q.empty()){
        auto u=q.front();
        q.pop();
        for(auto x:adj[u]){
            if(!visited[x]){
                //parent[x]=u;
                visited[x]=true;
                dis[x]=dis[u]+1;
                q.push(x);
            }
        }
    }
}

long long power(long long x,long long y){  
    long long ans=1;
    x%=mod;
    while(y>0){
        if(y&1) ans=(ans*x)%mod;
        y>>=1;
        x=(x*x)%mod;
    }
    return ans;
}

long long modinv(long long b){ 
    return power(b,mod-2);
}

long long dp[3004][3004][2];
long long arr[3004];
long long solve(long long l, long long r, long long flag, long long su){
    if(l>r)return 0;
    if(flag==0){
        if(dp[l][r][0]){
            return dp[l][r][0];
        }
        dp[l][r][0]=max(arr[l]+su-arr[l]-solve(l+1,r,0,su-arr[l]),arr[r]+su-arr[r]-solve(l,r-1,0,su-arr[r]));
        return dp[l][r][0];
    }
    else{
        if(dp[l][r][0]){
            return dp[l][r][0];
        }
        dp[l][r][0]=max(arr[l]+su-arr[l]-solve(l+1,r,0,su-arr[l]),arr[r]+su-arr[r]-solve(l,r-1,0,su-arr[r]));
        return dp[l][r][0];
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long n;
    cin>>n;
    for(long long i=0;i<n+2;i++){
        for(long long j=0;j<n+2;j++){
            dp[i][j][0]=dp[i][j][1]=0;
        }
    }
    long long su=0;
    for(long long i=0;i<n;i++){
        cin>>arr[i];
        su+=arr[i];
    }
    long long p=solve(0,n-1,0,su);
    cout1(p-(su-p));
    //cout2(su,p);
    return 0;
}