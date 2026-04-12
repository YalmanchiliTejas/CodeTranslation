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
#define deb(x) cout<<(#x)<<" "<<x<<endl
using namespace std;
lli mod = 1e9 +7,test; 
lli max(lli a,lli b){return a>b?a:b;}
lli min(lli a,lli b){return a>b?b:a;}

lli gcd(lli a, lli b) { 
   if (b == 0) return a; 
   return gcd(b, a % b);  
} 

string s;
lli d;

lli dp[10001][2][101];

lli f(lli idx , lli chk , lli sum){
    if(idx == s.length()){
        return sum %d == 0;
    }
    if(dp[idx][chk][sum] !=-1){return dp[idx][chk][sum];}
    lli here = 0;
    lli lmt = s[idx] - '0';
    if(chk){lmt = 9;}
    for(lli i = 0;i<=lmt;i++){
        lli next =chk;
        if(i < s[idx]- '0'){next = true;}
        here += (f(idx + 1, next , (sum + i)%d));
        here %= mod;
    } 
    dp[idx][chk][sum] = here;
    return here;
}

void solve(){
    cin>>s>>d;
    fo(i,10001){
        fo(j,2){
            fo(k,d+1){
                dp[i][j][k] =-1;
            }
        }
    }
    cout<< (f(0 , false , 0) - 1 + mod)%mod<<endl;
}

int main(){
    ULTRA_INSTINCT;
    lli t =1;
    fo(i,t){
        solve();
    }
    return 0;

}