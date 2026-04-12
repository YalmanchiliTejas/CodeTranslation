      #include<bits/stdc++.h>
      using namespace std;
      #define ll long long
      #define pb push_back
      #define pll  pair <long long,long long>
      #define mp make_pair
      #define ss second
      #define ff first
      #define maa 1000000007
      #define endl '\n'
      #define ld long double
      #define all(x) x.begin(),x.end()
      ll  power(ll  i,ll  j)
      {
        if(j==0)
        return 1 ;
        ll t=power(i,j/2)%maa ;
        if(j%2==0)
        return (t%maa*t%maa)%maa ;
        else
        return ((t%maa*t%maa)%maa*(i%maa)%maa)%maa ;
      }
      bool is(ll  i)
      {
        if(i==1)
            return 0 ;
        ll  f=0 ;
        for(ll  j=2;j<=sqrt(i);j++)
        {
            if(i%j==0)
            {
                f=1 ;
                break ;
            }
        }
        return !f ;
      }
      ll n ;
      ll ar[3001] ;
      ll dp[3001][3001] ;
      ll fun(ll i,ll j)
      {
          if(i>j)
          return 0 ;
          else if(i==j)
          return ar[i] ;
          else if(dp[i][j]!=-1)
          return dp[i][j] ;
          else
          {
              ll ans=max(ar[i]+min(fun(i+1,j-1),fun(i+2,j)),ar[j]+min(fun(i+1,j-1),fun(i,j-2))) ;
              
              return dp[i][j]=ans ;
          }
      }
      int main()
      {

        /// 50-4
        /// freopen("input.txt","r",stdin);
        /// freopen("output.txt","w",stdout);
        cin>>n ;
        ll sum=0 ;
        for(ll i=1;i<=n;i++)
        {cin>>ar[i] ;
         sum+=ar[i] ;
        }
        
        for(ll i=0;i<3001;i++)
        {
            for(ll j=0;j<3001;j++)
            dp[i][j]=-1 ;
        }
        cout<<(2*fun(1,n)-sum)<<endl ;
        
       
        
        

      }






