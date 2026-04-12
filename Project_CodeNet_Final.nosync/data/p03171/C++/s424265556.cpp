#include<bits/stdc++.h>
#define endl '\n'
#define PI 3.14159265358979323844
#define DECIMAL(n)  std::cout << std::fixed;std::cout << std::setprecision(n);
#define mp make_pair
#define pb push_back
#define int long long int 
#define forr(i,a,b) for (int i= a; i <b; ++i)
    using namespace std; 
    int dp[4000][4000];

int mixtures(int * a, int s ,int e){
        if(s>e)return 0;
        if (dp[s][e]!=-1)return dp[s][e]; 
      dp[s][e]=max( (a[s]+min(mixtures(a,s+2,e), mixtures(a,s+1,e-1))), (  a[e]+min(mixtures(a,s+1,e-1),mixtures(a,s,e-2))));
      return dp[s][e]; 
    }
    
    signed main(){
        int n;cin>>n; int sum=0;
        int a[n];forr(i,0,n) {cin>>a[i];sum+=a[i];}
        memset(dp,-1, sizeof dp);
        cout<< (2*mixtures(a,0,n-1) -(sum));
    }