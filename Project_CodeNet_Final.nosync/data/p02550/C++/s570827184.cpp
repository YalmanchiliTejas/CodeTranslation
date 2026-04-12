#include<bits/stdc++.h>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds; 
 
#define int long long 
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>
#define ff first
#define ss second
#define vi vector<ll>
#define vii vector<vector<ll>>
#define vpi vector<pii>
#define mod 1000000007
#define MOD 1000000007
#define full(a) a.begin(),a.end()
#define inf INT_MAX
#define minf INT_MIN
#define dd double
#define fori(x,n) for(ll i=x;i<n;i++)
#define umap unordered_map<ll,ll>
#define mmap map<ll,ll>
#define mm 998244353

// typedef tree<pii,null_type,less<pii>,rb_tree_tag,
// tree_order_statistics_node_update>PBDS; 



int32_t main() 
{ 
  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif  
   

    ll t;
    t=1;
    // cin>>t;
    while(t--){
     ll n,x,m;
     cin>>n>>x>>m;
     
     ll i = x;

     umap mpp;
     ll cnt = 1;

     // finding the starting point and length of the loop
     while(mpp[i]==0){
      // cout<<i<<" ";
       mpp[i] = cnt;
       i = (i*i)%m;
       cnt++;
     }
     // cout<<i<<" ";

     ll start = mpp[i],length = cnt-mpp[i];

     // cout<<start<<" "<<length<<" ";

     ll ans1 = 0;

     ll tt = x;
     for(int j=1;j<start;j++){ans1+=tt;
      tt = (tt*tt)%m;}

    ll remaining = (n-start+1)%length;

     ll ans2 = 0;
     ll ans3 = 0;

     for(int j=1;j<=length;j++){
      ans2+=tt;
      if(j==remaining)ans3 = ans2;
      tt = (tt*tt)%m;
     }

     // cout<<ans1<<"\n";


     cout<<ans1+ans3+ans2*((n-start+1)/length);








     

     

    

     

  






    }
      
     
      

      

    

    
return 0;
}     

