#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back 
const int mod=1e9+7;
long long  dp[3005][3005];
/*
ll solve(vector<ll>v,int i,int j){
	// for(int i=0; i<v.size(); i++)
      //   { cout<<v[i]<<" ";  }
		// cout<<endl;
	       if(i==j)
	        return dp[i][j]=v[i];
	       if(j-i == 1)
	         return dp[i][j]=max(v[i]-v[j],v[j]-v[i]);
	      
	       if(dp[i][j]!=-1)
	          return dp[i][j];
	          
		
	        ll sum1= v[i]-solve(v,i+1,j);
	        ll sum2=v[j]-solve(v,i,j-1);
	      //  cout<<sum1<<" "<<sum2<<" "<<i<<" "<<j<<endl;
	  return dp[i][j]= max(sum1 ,  sum2);
}  */
int main(){
      ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);
      ll n;
         cin>>n;
         vector<ll>v(n);
         ll sum=0;
         for(int i=0; i<n; i++)
         { cin>>v[i];
			  sum+=v[i];}
			  memset(dp,-1,sizeof(dp));
       //  cout<<solve(v,0,n-1)<<endl;
         
         for(int i=0; i<n; i++)
            dp[i][i]=v[i];
           
         for(int i=1; i<n; i++) {
            for(int j=0; j<n-i ;j++){
			    int k=i+j;
			    dp[k][j]=max(v[k]-dp[k-1][j], v[j]-dp[k][j+1]);
		      
		   }
		}
		cout<<dp[n-1][0]<<endl;
     }
