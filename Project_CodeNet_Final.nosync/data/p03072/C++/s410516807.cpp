#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
                
#define speedio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pretime float(clock()-clk)/CLOCKS_PER_SEC
#define max2(a,b) ((a)>(b) ? (a) : (b))   
#define min2(a,b) ((a)<(b) ? (a) : (b)) 
#define rep(i,a,b) for(i=a;i<=b;++i)
#define rev(i,a,b) for(i=a;i>=b;--i) 
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define lli long long int 
#define ins insert
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define PI 3.14159265
#define mod 1000000007
#define inf 1000000000000000

using namespace std;
typedef vector<lli>   vll;
typedef vector<int>   vi;
typedef set<lli>      sll;
typedef set<int>      si;
typedef pair<lli,lli> pll;
typedef pair<int,int> pii;
clock_t clk=clock();       

int i,j;
void solve(void);

int main()
{
  speedio;
   int t=1;  
  // cin>>t;
   while(t--)
     solve();

  return 0;
}
//
void solve()
{
	int n; cin>>n;
	lli a[n];
	rep(i,0,n-1) cin>>a[i];
 lli max=-1; int ct=0;
	rep(i,0,n-1)
	  if(a[i]>=max)
       {
	  	 max=a[i]; ++ct;
       }

       cout<<ct<<"\n";
}