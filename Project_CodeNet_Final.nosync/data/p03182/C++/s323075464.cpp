#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<pii,ll> piii;
typedef pair<ll,pii> ipii;
#define MOD 1000000007
#define mod(a) ((a)%MOD)
#define pb push_back
#define ft first
#define sd second
#define mp make_pair
#define dbg(x) cerr<<#x<<" = "<<x<<"\n"
#define dbg2(x,y) cerr<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<"\n"
#define dbg3(x,y,z) cerr<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<" , "<<#z<<" = "<<z<<"\n"
#define INF (1LL<<60)
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;*/
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(v) v.begin(),v.end()
#define endl '\n'
ll gcd(ll a,ll b){if(a==0) return b; return gcd(b%a,a);}
ll powm(ll base,ll exp,ll mod=MOD) {base%=mod;ll ans=1;while(exp){if(exp&1LL) ans=(ans*base)%mod;exp>>=1LL,base=(base*base)%mod;}return ans;}
 


vector<pii> p[200005];
ll tree[800005];
ll lazy[800005];


void lazy_update(int node,int s,int e){
    tree[node]+=lazy[node];
    if(s!=e){
      lazy[2*node]+=lazy[node];
      lazy[2*node+1]+=lazy[node];
    }
    
    lazy[node]=0;  
}

void update(ll node,ll s,ll e,ll l,ll r,ll val){
     if(lazy[node]!=0) lazy_update(node,s,e);
     if(s>r||e<l) return;
     if(l<=s&&e<=r){
         tree[node]+=val;
         if(s!=e){
             lazy[2*node]+=val;lazy[2*node+1]+=val;
         }
     }
     else{
        ll mid = (s+e)/2;
        update(2*node,s,mid,l,r,val);
        update(2*node+1,mid+1,e,l,r,val);
        tree[node]=min(tree[2*node],tree[2*node+1]);
     }
}

ll query(ll node,ll s,ll e,ll l,ll r){
     if(s>r||e<l) return INF;
     if(lazy[node]!=0) lazy_update(node,s,e);
     if(l<=s&&e<=r) return tree[node];
     else{
        ll mid = (s+e)/2;
        ll q1=query(2*node,s,mid,l,r);
        ll q2=query(2*node+1,mid+1,e,l,r);
        return min(q1,q2);
     }
}


int main(){
      sync;
      ll n,m;
      cin>>n>>m;
      ll sum=0;
      for(ll i=1; i<=m; i++){
            ll l,r,a;
            cin>>l>>r>>a;
            p[r].pb({l,a});
            sum+=a;
      }
 
       ll ans;
       ll a_sum=0;
       for(int i=1;i<=n+1;i++){
           for(auto it:p[i-1]){
                update(1,1,n,1,it.ft-1,it.sd);
                a_sum+=it.sd;
           }
            ll temp = min(a_sum,query(1,1,n,1,i-1));
            update(1,1,n,i,i,temp);
            if(i==n+1) ans=temp;
       }

          cout<<sum-ans<<endl;
}
