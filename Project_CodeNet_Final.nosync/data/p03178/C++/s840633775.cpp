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
      string s ;
      ll d ;
      ll dp[10001][101][2] ;
      ll fun(ll i,ll j,ll k)
      {
          if(i==s.length())
          {
              if(j==0)
              return 1 ;
              else
              return 0 ;
          
          }
          else if(dp[i][j][k]!=-1)
          return dp[i][j][k]%maa ;
          else
          {
              ll nj=j ;
              nj%=d ;
              nj+=(ll)(s[i]-'0') ;
              nj%=d ;
              ll ans=fun(i+1,nj,k)%maa ;
              
              for(ll u=0;u<(ll)(s[i]-'0');u++)
              {
                  nj=j ;
                  nj%=d ;
                  nj+=u ;
                  nj%=d ;
                  ans+=fun(i+1,nj,0)%maa ;
                  ans%=maa ;
              }
              if(k==0)
              {
               for(ll u=(ll)(s[i]-'0')+1;u<=9;u++)
              {
                  nj=j ;
                  nj%=d ;
                  nj+=u ;
                  nj%=d ;
                  ans+=fun(i+1,nj,0)%maa ;
                  ans%=maa ;
              }
              }
              
              return dp[i][j][k]=ans%maa ;
              
          }
      }
      int main()
      {

        /// 50-4
        /// freopen("input.txt","r",stdin);
        /// freopen("output.txt","w",stdout);
        cin>>s>>d ;
        for(ll i=0;i<=10000;i++)
        {
            for(ll j=0;j<=100;j++)
            {
                for(ll k=0;k<2;k++)
                dp[i][j][k]=-1 ;
            }
        }
        cout<<(fun(0,0,1)-1+maa)%maa ;
        
       
        
        

      }






