/*
       ()       ()()()()     ()        ()       ()        ()        ()
      ()()      ()     ()    ()()      ()      ()()       ()()      ()
     ()  ()     ()      ()   ()  ()    ()     ()  ()      ()  ()    ()
    ()()()()    ()      ()   ()    ()  ()    ()()()()     ()    ()  ()
   ()      ()   ()     ()    ()      ()()   ()      ()    ()      ()()
  ()        ()  ()()()()     ()        ()  ()        ()   ()        ()

*/
#include <bits/stdc++.h>
#define MOD  (int)(1e9+7)
#define SIZE (int)(1e5+5)
#define all(x) x.begin(),x.end()
#define si(i)  scanf("%d",&i)
#define sf(f)  scanf("%f",&f)
#define pi(i)  printf("%d",i)
#define pd(d)  printf("%lf",d)
#define deb(x) cout<<#x<<" is "<<x<<"\n";
#define lb     lower_bound
#define ub     upper_bound
#define pb     push_back
#define prDouble(x) cout<<fixed<<setprecision(10)<<x;
#define IOfast ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int64_t exponentiation(int64_t base,int exp)
{
    if (exp == 0)
        return 1;

    if (exp == 1)
        return base;

    int64_t t = exponentiation(base, exp / 2);

    t = (t * t);

    if (exp % 2 == 0)
        return t;
    else
        return base * t;
}
int64_t dp[3001][3001];

int64_t solve(vector<int64_t>& arr,int start,int end)
{   
  if(start > end)
    return 0;

  if(dp[start][end] != -1)
  
    return dp[start][end];
  
  
  dp[start][end] = max( arr[start] + min( solve(arr,start+2,end ), solve(arr,start+1,end-1 )) 
                      , arr[end] + min( solve(arr,start,end-2 ), solve(arr,start+1,end-1 )) );

  return dp[start][end];  
}


int main()
{
  IOfast;
  int q=1;
  //cin>>q;
  memset(dp,-1,sizeof(dp));
  while(q--)
  {
    int n,k;
    cin>>n;
    vector<int64_t> arr(n);
    for(auto &item:arr) cin>>item;

    int64_t X = solve(arr,0,n-1); //taro started this game ;  
    int64_t sum = accumulate(all(arr),(int64_t)0);
    cout<<2*X - sum;
    //out<<"X is "<<X<<"\nY is "<<sum-X;
  }
  return 0;
}
