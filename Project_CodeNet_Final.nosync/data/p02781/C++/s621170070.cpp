#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld  double
#define pii pair<int,int>
#define pb push_back
#define M 103
#define inf (ll)1e9+11
#define warmup ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int mod=1e9+7;  
int dp[M][M][2], K; 
  
int countInRangeUtil(int pos, int cnt, int tight,               string num) 
{ 
    if (pos == num.size()) 
    { 
        if (cnt == K) 
            return 1; 
        return 0; 
    } 
  
    if (dp[pos][cnt][tight] != -1) 
        return dp[pos][cnt][tight]; 
  
    int ans = 0; 
  
    int limit = (tight ? 9 : num[pos]-'0'); 
  
    for (int dig = 0; dig <= limit; dig++) 
    { 
        int currCnt = cnt; 
  
        if (dig != 0) 
            currCnt++; 
  
        int currTight = tight; 
  
        if (dig < num[pos]-'0') 
            currTight = 1; 
  
        ans += countInRangeUtil(pos + 1, currCnt,                              currTight, num); 
    } 
    return dp[pos][cnt][tight] = ans; 
} 
  
int countInRange(string num) 
{   
    memset(dp, -1, sizeof(dp)); 
    return countInRangeUtil(0, 0, 0, num); 
} 
  
int main() 
{ 
    string n;
    cin>>n>>K;
    cout<<countInRange(n);
    
    return 0; 
} 