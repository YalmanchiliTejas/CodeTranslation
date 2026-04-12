#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long
#define endl '\n'
#define inf 9223372036854775807
#define maxn 3000001
#define mod (ll)(1e9+7)
#define int ll
 
using namespace std;
 
void io(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}

int n,ar[maxn];
int dp[maxn];
int sum=0;


void __solve(){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>ar[i];
		}
		dp[1]=0;
		sum=ar[1];
		for(int i=2;i<=n;i++){
			dp[i]=dp[i-1]+sum*ar[i];
			dp[i]%=mod;
			sum+=ar[i];
			sum%=mod;
		}
		cout<<dp[n]<<endl;
		
}


int32_t main(){
io();
IOS;    
			int t=1;
			// cin>>t;
			while(t--){
				__solve();
			}
		
		



        

        


        
    
        
        
                


 
        
 
 
 
        
 
 
 
 
        
        
 
        
        
 
    
    
    
    
 
 
       
 
 
 
 
      
   
 
 
 
 
}