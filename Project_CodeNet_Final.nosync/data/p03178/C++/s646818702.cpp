#include<bits/stdc++.h>

/*
#pragma GCC optimize("-Ofast")
//#pragma GCC optimize("trapv")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")*/

#define I inline void 
#define S struct 
#define vi vector<int> 
#define vii vector<pair<int,int>>
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std ; 
using ll = long long ; 
using ld = long double ; 

const int N = 1e4 + 7 , mod = 1e9 + 7 ; 
const int inf = N ; 
// How interesting!

int n , d ; 
string k ; 
int dp[N][101][2] ; 

int solve(int i , int md, bool flag){
        if(i == n)
                return !md ; 
        
        if(~dp[i][md][flag])
                return dp[i][md][flag] ;
        int ret = 0 ; 

        for(int j = 0 ;j < 10 ;j ++){
                if(flag && j > k[i] - '0')
                        continue ; 
                ret += solve(i + 1 , (md + j) % d , (flag & (j == k[i] - '0')) ) ; 
                if(ret>=mod)
                        ret-=mod ;
        }

        return dp[i][md][flag] = ret ; 
}

int main(){
        ios_base::sync_with_stdio(0) ;
        cin.tie(0) ; 
        //freopen("in.in" , "r" , stdin) ; 
        memset(dp , -1 , sizeof dp) ; 
        cin >> k >> d ;

        n = (int) k.size() ;

        cout<< (solve(0 , 0 , 1) + mod - 1 ) % mod ; 


        return 0 ; 
}