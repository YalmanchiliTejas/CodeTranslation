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
    Digit DP
    For prerequiste check-->https://codeforces.com/blog/entry/53960
    Considering given number as sequence of digits you can see overlapping subproblems
    ex- 234
    stage 1)             0      1                      2
    stage 2)           [0..9]  [0..9]              [0..2]         3
    stage 3)       10X[0..9]  10X[0..9]          3X[0..9]        [0..3]   4
    suppose
    stage 1) we get digit '1' so number of non -zero till now one
    stage 2) we will calculate dp[0][1][k-1];
    same will be calculate if we choose '2 in the first stage
    this confirms overlapping subproblems...
     
    
*/
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
int digit_dp[2][101][5];
string s;
int k;
int recursion(int flag,int pos,int left_nonzero)
{
    int num=0,i;
    if(digit_dp[flag][pos][left_nonzero]!=-1)return digit_dp[flag][pos][left_nonzero];
    if(left_nonzero<0)return 0;
    if(pos==(int)sz(s))
    {
        num=(!left_nonzero?1:0);
        digit_dp[flag][pos][left_nonzero]=num;
        return digit_dp[flag][pos][left_nonzero];
    }
    
        if(flag)//flag==1 implies that the formed number is less than N
        {
            foe(i,0,9)
            num+=recursion(1,pos+1,(i?left_nonzero-1:left_nonzero));//if i is zero don't decrease count of leftnonzero
            
            digit_dp[flag][pos][left_nonzero]=num;
            return digit_dp[flag][pos][left_nonzero];
            
        }
        else//flag==0 implies that the formed number is equal to N(uptil pos i.e now)
        {
            int lmt=s[pos]-'0';
            fo(i,0,lmt)
            num+=recursion(1,pos+1,(i?left_nonzero-1:left_nonzero));
            
            num+=recursion(0,pos+1,(lmt?left_nonzero-1:left_nonzero));
            digit_dp[flag][pos][left_nonzero]=num;
            return digit_dp[flag][pos][left_nonzero];
        }
    
}
void init()
{
    int i,j,K;
    fo(i,0,2)
    fo(j,0,101)
    fo(K,0,5)digit_dp[i][j][K]=-1;
}
void solve()
{
    init();
    cin>>s>>k;
    cout<<recursion(0,0,k);
    cout<<"\n";
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

