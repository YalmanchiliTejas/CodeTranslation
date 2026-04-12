#include<bits/stdc++.h>
#include<iostream>
#define ll long long 
#define ld long double
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define all(v) v.begin(),v.end()
#define sz(v) sizeof(v)
#define MOD 1000000007
#define MAX (ll)1e12+5


using namespace std;


int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
//////
// prime Seive
/*
bitset<1000005> bt;
//unordered_map<ll,bool> is_prime;
vector<ll> primes;
void pS(ll n){
    ll val = min(n+1,(ll)1000006);
    for(ll i=3;i<=val;i+=2){
        bt[i] =true;
    }
    bt[0] =false;
    bt[1] =false;
    bt[2] =false;
    //is_prime[2] =true;
    primes.pb((ll)2);
    for(ll i=3;i<=val;i+=2){
        if(bt[i])
            for(ll j=i*i;j<=val;j+=2*i)
                bt[j] =false;
    }
    for(ll i=3;i<=val;i+=2){
        if(bt[i]){primes.pb(i);
        //is_prime[i]=true;
        //cout<<i<<" :PRIME\n";
        }
    }
    return;
}
*/          
/////
// Fenwick Tree
/*
BIT[200005] ={0};
//BUILD BIT
// for(int i=1;i<1;i++){ cin>>a[i];update(i,a[i],n);};
 
void update(int i,int val,int n){
    while(i<=n){
    BIT[i]+= inc;
    i+= (i&(-i));
    }
}
ll query(int i){
    ll ans =0;
    while(i>0){
        ans+= BIT[i];
        i-=(i&(-i));
    }
    return ans;
}
 
*/
//__builtin_popcount(4)
ll logPow(ll a,ll b){
    ll ans=1;
    while(b>0){
        if(b&1){
            ans*=a;
        }
        a*=a;
        b= b>>1;
    }
    return ans;
}

ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}
ll lcm(ll a,ll b){
    return (a*b)/gcd(a,b);
}



/*
// dsu
const int N = 500009;
int p[N],cmp[N];
int getP(int cn){
    return ((cn==p[cn])?cn:(p[cn]=getP(p[cn])));
}

void unite(int a,int b){
    a = getP(a);
    b = getP(b);
    if(a==b) return ;
    if(cmp[a]<cmp[b])
        swap(a,b);
    p[b] = a;
    cmp[a] += cmp[b];
}
*/

/*
//dfs
bool dfs(ll src ,ll dest,unordered_map<ll,bool> &vis,unordered_map<ll,vector<ll>> &g){
    vis[src] =true;
    if(src== dest) return true;
    bool  ans =false;
    for(auto nbr: g[src]){
        if(!vis[nbr])
            ans = ans|dfs(nbr,dest,vis,g);
    }
    return ans;
}

*/
// bfs
/*
ll bfs(ll i,unordered_map<ll,bool> &vis){
    queue<ll> q;q.push(i);vis[i] =true;ll ans =0;
    while(!q.empty()){
        ans++;ll cur = q.front();q.pop();
        for(auto nbr: g[cur]){
            if(!vis[nbr]){
                vis[nbr] =true;q.push(nbr);
    }}}
    return ans;
}
*/

unordered_map<ll,vector<ll>> g;

ll modPow(ll a,ll b){
    ll ans =1;
    while(b>0){
        if(b&1){
            ans*=a;
            ans= (ans+MOD)%MOD;
        }
        a*=a;
        a= (a+MOD)%MOD;
        b = b>>1;
    }
    return  ans;
}


int main(){
    ll t=1; 
    //cin>>t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(t--){
        int n; cin>>n;
        if(n>=30){
            cout<<"Yes\n";
        }
        else cout<<"No\n";
        
    }
    return 0;
}