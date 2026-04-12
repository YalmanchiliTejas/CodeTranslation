#include<bits/stdc++.h>

using namespace std ; 

const int N = 1e6 +  7 ; 

long long n , ans =-1e17 ; 
long long a[N]  ; 
long long dp[N][5] ; 


long long solve(int i , int rem ){
    if(i>=n)return 0 ; 
    if(dp[i][rem]!=-1)return dp[i][rem] ; 
    long long ret = -1e18;     
    ret = max(ret ,  a[i] +  solve(i+2 , rem) ) ; 
    for(int j = 1 ;  j<=rem ;j ++){
        ret = max(ret , a[i] + solve( i+2 + j , rem - j) ) ; 
    }
    return dp[i][rem] = ret ; 
}

int main(){
    memset(dp , -1 , sizeof dp )  ; 
    ios_base::sync_with_stdio(0) ; 
    cin.tie(0) ;    
    //freopen("in.in" , "r" , stdin) ; 
    cin>>n ; 
    for(int i = 0 ;i <  n;i++){
        cin>>a[i] ;
    }
    if(n%2){
        ans = max(ans , solve(0 , 2) ) ; 
        ans = max(ans , solve(1 , 1)) ; 
        if(n > 2)
        ans = max(ans , solve(2 , 0)) ; 
    }
    else{
        ans = max(ans , solve(0 , 1) ) ;
        ans = max(ans , solve(1 , 0)) ; 
    }
    cout<<ans ;  
    return 0 ; 
}