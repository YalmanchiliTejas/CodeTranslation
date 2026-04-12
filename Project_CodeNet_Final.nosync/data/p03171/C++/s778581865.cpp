#include<bits/stdc++.h>
using namespace std;
#define mod 993244853
#define ll long long
#define debug(x) printf("\n'x is: %lld'\n\n",x);
#define lp(i,l,r) for(ll i=l;i<r;i++)
//VECTOR
#define pb push_back
#define pop pop_back
//PAIR
#define fst first
#define snd second
#define mp make_pair

ll invmod(ll a,ll b)
{
  ll i=1, m=b-2;

  while(m)
  {
    if(m&1)(i=i*a)%b;

    m>>=1;
    a=(a*a)%b;
  }
return i;
}

ll n=0,a[4000]={0},dp[4000][4000],cum[4000]={0};

ll diff(ll l, ll r)
{
 if(l==0)
   return cum[r];
 else
   return cum[r]-cum[l-1];
}

ll rec(ll l,ll r)
{
 if(l>r)
   return 0;
  
 if(dp[l][r]==-1)
   dp[l][r] = max(diff(l,r)-rec(l+1,r) , diff(l,r)-rec(l,r-1));

 return dp[l][r];
}

int main()
{
  ios::sync_with_stdio(false);

  cin>>n;

  lp(i,0,n)
  {
    cin>>a[i];
    
    if(i>0)
      cum[i]=cum[i-1]+a[i];
    else
      cum[i]=a[i];
  }

  lp(i,0,4000)
    lp(j,0,4000)
     dp[i][j]=-1;

  cout<<(2*rec(0,n-1) - cum[n-1])<<endl;

return 0;
}
