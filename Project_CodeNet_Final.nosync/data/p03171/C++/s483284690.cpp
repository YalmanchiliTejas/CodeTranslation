#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(x) push_back(x)
#define f(i,st,n) for(i=st;i<n;i++)
#define vec vector
#define mst(a,b) memset(a,b,sizeof(a))
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define mod 1000000007
#define sfl(x) scanf("%lld",&x)
#define pfl(x) printf("%lld\n",x)
#define pf(x) printf("%lld",x)
#define all(v) v.begin(),v.end()
#define mpr make_pair
#define fs first
#define se second
#define inf LLONG_MAX
#define nnf LLONG_MIN
 
 
 
ll gcd(ll a,ll b){
    if(a==0){
        return b;
    }                     
    return gcd(b%a,a);
}
ll power(ll x,ll y){            
    ll res=1;
    while(y>0){
        if(y%2==1){
            res=((res%mod)*(x%mod))%mod;
        }
        x=((x%mod)*(x%mod))%mod;
        y=y/2;
    }
    return res;
}
 
 struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(pair<uint64_t,uint64_t> x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x.first + FIXED_RANDOM)^(splitmix64(x.second + FIXED_RANDOM) >> 1);
  }
};

void get_time(auto start,auto end){
    double time_taken =  
      chrono::duration_cast<chrono::nanoseconds>(end - start).count(); 
  
    time_taken *= 1e-9;
    cout<<"\n";
    cout<<"Time taken : "<<fixed<<time_taken<<setprecision(6);
}

  
  ll n,dp[3000][3000],a[3000];

  ll fn(ll i,ll j,ll s){
    if(i==j)return a[i];

    if(dp[i][j]!=0)return dp[i][j];

    return dp[i][j]=max(s-fn(i+1,j,s-a[i]),s-fn(i,j-1,s-a[j]));

  }

int main(){

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

  auto start = chrono::high_resolution_clock::now();

  
 

/* #ifndef ONLINE_JUDGE
    
   freopen("input.txt", "r", stdin);
   
   freopen("output.txt", "w", stdout);
   #endif*/

    cin>>n;



    ll s=0;

    for(int i=0;i<n;i++){
      cin>>a[i];
      s+=a[i];
    }

    ll x=fn(0,n-1,s);

    cout<<2*x-s;


   



  auto end = chrono::high_resolution_clock::now();

  /*#ifndef ONLINE_JUDGE

   get_time(start,end); 

  #endif*/

    return 0;
 }