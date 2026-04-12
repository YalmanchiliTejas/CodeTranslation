#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int A[3010];
int cum[3010];
int dp[3010][3010];

int f(int p1, int p2){
     if(p1==p2) return A[p1];
    int&ans=dp[p1][p2];
    if(ans!=-1) return ans;
    
     ans=0;
     int total;
     if(p1==0) total=cum[p2];
     else total=cum[p2]-cum[p1-1];
     ans =max(ans, total-f(p1+1, p2));
     ans =max(ans, total-f(p1, p2-1));
     return ans;
}

int32_t main(){
     memset(dp, -1, sizeof(dp));
     cin>>n;
     for(int i=0;i<n;i++)cin>>A[i];
     cum[0]=A[0];
     for(int i=1;i<n;i++)cum[i]=cum[i-1]+A[i];
    
     int a=f(0, n-1);
     cout<<a-(cum[n-1]-a);
}