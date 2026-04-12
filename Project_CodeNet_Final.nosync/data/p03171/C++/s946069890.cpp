#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <string>
#include <utility>
#include <map> 
#include <queue>
#include <stack>
#include <iomanip>
#include <sstream>
#define MP make_pair
#define PB push_back
#define S size()
#define B begin()
#define E end()
#define ll long long
#define REP(i,a,n) for(ll i=a; i<n; ++i)
#define RED(i,n,a) for(ll i=n; i>=a; --i)
#define m9 1000000007
#define endl "\n"
#define F first
#define SE second
#define ld long double



using namespace std;

ll gcd(ll a, ll b){
    if(a%b==0){
        return b;
    }
    else{
        return gcd(b, a%b);
    }
}
ld area(ld x1, ld y1, ld x2, ld y2, ld x3, ld y3){
    return abs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2;
}
 
ll dp[3001][3001];
bool vis[3001][3001];
ll n;
vector <ll> v;



ll solve(ll l, ll r){
    if(vis[l][r]){
        return dp[l][r];
    }
    vis[l][r]=1;
    if(l==r ){
        dp[l][r]=v[l-1];
        return dp[l][r];
    }
    
    dp[l][r]= max(v[l-1]-solve(l+1,r),v[r-1]-solve(l,r-1));
    return dp[l][r];
    
}

int main(){
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cin>>n;
    REP(i,0,n){
        ll x;
        cin>>x;
        v.PB(x);
    }
    REP(i,0,301){
        REP(j,0,301){
            dp[i][j]=0;
        }
    }
    cout<<solve(1,n);
    
    
    
    
}
