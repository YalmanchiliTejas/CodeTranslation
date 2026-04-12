#include <bits/stdc++.h>
//#include "Header.h"

#define pi 3.14159265358979323846264

#define ll long long
#define fori(n) for(long long i=0;i<n;i++)
#define forj(n) for(long long j=0;j<n;j++)

#define sp(n) setprecision(n)
#define d7 1000000007
#define mkp make_pair
#define mkt make_tuple

using namespace std;

bool isPrime(long long k){
    if(k<=1){return false;}
    if(k==2){return true;}
    if(k%2==0){return false;}
    long long i = 3;
   while (i*i <= k) {if (k % i == 0) {return false;}i += 2;}
return true;
}

ll binomialCoeff(ll n, ll k){
    ll C[n + 1][k + 1];ll i, j;
    for (i = 0; i <= n; i++){
        for (j = 0; j <= min(i, k); j++){
            if (j == 0 || j == i){C[i][j] = 1;}
            else{C[i][j] = (C[i - 1][j - 1]%d7 + C[i - 1][j]%d7)%d7;}}}
    return C[n][k]%d7;
 }

ll gcd(ll a, ll b){if (b == 0)
        return a;return gcd(b, a % b);}

ll srihrg(ll n,ll k,ll m){
    ll ans;
    ans=1;
    fori(k){
        ans=(ans*n)%m;
    }
    return ans;
}

ll kk=1;
void dfsi(vector<bool> &vis, vector<ll> adj1[], ll n, ll start, vector<ll> &pre, vector<ll> &pos){
    vis[start]=true;
    pre[start]=kk;kk++;
    for(ll i: adj1[start]){
        if(!vis[i]){
            vis[i]=true;
            dfsi(vis,adj1,n,i,pre,pos);
        }
    }
    pos[start]=kk;kk++;
}

void bfsi(vector<ll> &dis, vector<ll> adj[], ll s, vector<ll> &parent){
    dis[s]=-1;
    queue<ll> q;
    q.push(s);
    while(!q.empty()){
        ll z=q.front();
        q.pop();
        for(ll v:adj[z]){
            if(dis[v]==0){
            q.push(v);
            dis[v]=-dis[z];
                parent[v]=z;}
        }
    }
}

void make_set(ll v, vector<ll> &parent, vector<ll> &krank) {
    parent[v] = v;
    krank[v] = 0;
}

ll find_set(ll v,vector<ll> &parent, vector<ll> &krank) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v], parent, krank);
}

void union_sets(ll a, ll b,vector<ll> &parent, vector<ll> &krank) {
    a = find_set(a,parent,krank);
    b = find_set(b,parent,krank);
    if (a != b) {
        if (krank[a] < krank[b])
            swap(a, b);
        parent[b] = a;
        if (krank[a] == krank[b])
            krank[a]++;
    }
}

void dijkstra(ll s, vector<ll> &dist, vector<ll> &parent, ll n, vector<pair<ll,ll>> adj[]){
    dist[s]=0;
    vector<bool> u(n,false);
    fori(n){
        ll v=-1;
        forj(n){
            if(!u[j] &&(v==-1||(dist[j]<dist[v]))) v=j;
        }
        if(dist[v]==d7) break;
        u[v]=true;
        for(auto j:adj[v]){
            ll a,b;
            a=j.first;
            b=j.second;
            if(dist[v]+b<dist[a]){
                dist[a]=dist[v]+b;
                parent[a]=v;
            }
        }
    }
}


int main(int argc, const char * argv[]) {
 //cout<<"Om\n";
 //Praise to Lord
 //make cin/cout faster
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);cout.tie(NULL);
// code now
   
    ll n;
    //cin>>n;
    string s;
    cin>>s;
    if(s=="AAA"||s=="BBB"){
        cout<<"No";
    }else{cout<<"Yes";}
    
//code ends
    return 0;
}
