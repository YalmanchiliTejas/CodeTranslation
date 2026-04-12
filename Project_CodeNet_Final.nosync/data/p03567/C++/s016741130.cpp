#include<bits/stdc++.h>
#define MX 1000000
using namespace std ;

int W[10004], cost[10004], dp[104][1004], ans[1000] ;

int NS(int i, int w, int cap, int n){
    int p1, p2 ;
    if(i > n) return 0 ;
    if(dp[i][w] != -1) return dp[i][w] ;
    if(w + W[i] <= cap){
        p1 = cost[i] + NS(i+1, w + W[i], cap, n) ;
    }
    else{
        p1 = 0 ;
    }
    p2 = NS(i+1, w, cap, n) ;
    dp[i][w] = max(p1, p2) ;
    if(w+W[i] <= cap) ans[w+W[i]] = dp[i][w] ;
    return dp[i][w] ;
}
void solve(){
    string s ;
    cin>>s ;
    for(int i = 1; i < s.size(); i++){
        if(s[i-1] == 'A' && s[i] == 'C'){
            cout<<"Yes"<<'\n' ;
            return ;
        }
    }
    cout<<"No"<<'\n' ;
}
int main(){
    solve() ;
    return 0 ;
}