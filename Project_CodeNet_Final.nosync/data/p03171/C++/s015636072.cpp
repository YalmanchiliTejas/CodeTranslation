 #include <bits/stdc++.h>
using namespace std;
#define fr(i,k,n) for(int i=k;i<n;i++)
#define read(x) cin>>x
#define ll long long int
#define mod 1000000007 
#define print(x) cout<<x<<endl
#define pb(x) push_back(x)
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
int main() { 
    fastIO;
     int t=1,n ;
     //cin>>t;
     while(t--){
         cin>>n ;
       vector<int>a(n );
       vector<vector<ll>>dp(n,vector<ll>(n,0));
      // int x=0,y=0;
       fr(i,0,n ){ 
       cin>>a[i];
        
       }
       
       for(int l=n-1;l>=0;l--) 
         for(int r=l;r<n;r++){
           if(l==r)
             dp[l][r]=a[l];
           else
           {dp[l][r]=max(-dp[l+1][r]+a[l],-dp[l][r-1]+a[r]);
              
           }
          
        }
      cout<<dp[0][n-1]<<endl;}
	return 0;
}
