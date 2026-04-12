//AUTHOR: RAVAN_2070
//PUNE INSTITUTE OF COMPUTER TECHNOLOGY
/*
    I LOVE CLARICE STARLING

     ♥LOVE♥        ♥LOVE♥
  ♥LOVE♥♥LOVE♥  ♥LOVE♥♥LOVE♥
♥LOVE♥♥LOVE♥♥LOVE♥♥LOVE♥♥LOVE♥
   ♥LOVE♥♥LOVE♥♥LOVE♥♥LOVE♥
      ♥LOVE♥♥LOVE♥♥LOVE♥
         ♥LOVE♥♥LOVE♥
            ♥LOVE♥
               ♥


    EXPLAINATION BELOW->
    Game+dp 2
    some what like LCS
    And obviously Greedy approach of always choosing largest fails
    Check out testcase 
    6
    4 2 9 3 1 5
    it leads to 5 +2 +3 - 4 + 9 + 1;
    whereas actually 5 + 1 + 9 - 4 + 2 +3 
   
*/
//
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<pair<ll,ll>> vii;
typedef pair<ll,ll> pii;
typedef map<ll,ll> mii;
#define MOD7 1000000007
#define MOD9 1000000009
#define pi 3.1415926535
#define Test_cases ll TC;cin>>TC;while(TC--)
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
#define sp(x) fixed<<setprecision(x)
#define sz(x) (ll)(x.size())
#define fo(i,a,b) for(i=a;i<b;i++)
#define foe(i,a,b) for(i=a;i<=b;i++)
int n;
int A[3005];
ll dp_XY[3005][3005];
void solve()
{
    int i,j,interval;cin>>n;
    fo(i,0,n)cin>>A[i],dp_XY[i][i]=A[i];
    
    for(interval=1;interval<=n-1;interval++)
    {
        i=0;j=interval;
        while(j<n)
        {
          dp_XY[i][j]=max(A[i]-dp_XY[i+1][j],A[j]-dp_XY[i][j-1]);
          i++;j++;
        }
    }
    cout<<dp_XY[0][n-1]<<"\n";
   
}
int main()
{
   fastio
   solve();
  return 0;
}
//map<ll,ll,greater<int>> to sort in descending order ,in iterator declaration no greater<int>
//if you want to apply lowerbound on set use s.lower_bound(key),not the one used for vector
/* TIPS FOR DEBUGGING
 * Check if values are not overflowing (use long long where required)
 * Check if ranges are inclusive or not.
 * Check properly if greedy will work or not before using it.
 * Check EDGE CASES!! Seriously, even in 2B, saving 8 points by being
 * 2 minutes faster will bite you in the ass if you don't make sure
 * it works on edge cases.
 * Keep adding to this list.
*/
