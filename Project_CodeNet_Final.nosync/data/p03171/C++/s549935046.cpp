#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
#include<deque>
#include<stack>
#include<algorithm>
#include<iterator>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#define lli long long int
#define mp make_pair
#define ULTRA_INSTINCT ios_base::sync_with_stdio(false); cin.tie(0)
#define PI  3.141592653589793
#define fo(i,n) for(lli i=0;i<(n);i++)
#define FO(i,x,n) for(lli i=(x);i<(n);i++)
#define pb push_back
#define FI first
#define SE second
#define vi vector<lli>
#define pi pair<lli,lli>
#define vii vector<pi >
#define Endl endl
#define ITA 200005
#define ROH 100005
using namespace std;
lli mod = 1e9 +7,test; 
lli max(lli a,lli b){return a>b?a:b;}
lli min(lli a,lli b){return a>b?b:a;}

lli gcd(lli a, lli b) { 
   if (b == 0) return a; 
   return gcd(b, a % b);  
} 

lli n;
vi a(3001);

vector<vi > dp(3001, vi(3001,-1 * mod));

lli f(lli i,lli j){
    if(i>j){ return 0;}
    if(i==j){
        return a[i];
    }
    if(dp[i][j] != -1*mod){
        return dp[i][j];
    }
    return dp[i][j] = max( a[i] + min(f(i+2 , j) , f(i+1 , j-1) ) , a[j] + min(f(i , j-2) , f(i+1 , j-1) ) );
}


void solve(){
    cin>>n;
    lli sum = 0;
    fo(i,n){
        cin>>a[i];
        sum += a[i];
    }
    lli f1 = f(0,n-1);
    lli f2 = sum - f1;
    cout<<  f1 - f2 <<endl;


}

int main(){
    ULTRA_INSTINCT;
    lli t =1;
    // cin>>t;
    fo(i,t){
        solve();
    }
    return 0;

}