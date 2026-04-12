        #include <bits/stdc++.h>
        #define mp make_pair
        #define f1 first
        #define f2 second
        #define int long long
        #define int1 int
        #define pb push_back
        using namespace std;
        int dp[10009][19][109];
        main()
        {
            int z=1e9+7;
          string k;
          cin>>k;
          int d;
          cin>>d;
          int n=k.size();
          for(int i=0 ; i<=9 ; i++)
          {
              dp[1][i][(i%d)]=1;
          }
          for(int i=2 ; i<=n ; i++)
          {
              for(int j=0 ; j<10 ; j++)
              {
                  for(int w=0 ; w<d ; w++)
                  {
                      for(int a=0 ; a<10 ; a++)
                      {
                          dp[i][j][w]=((dp[i][j][w]+dp[i-1][a][(((w%d)-(j%d)+d)%d)])%z);
                      }

                  }
              }
          }
          int ans=0;
            int a=1;
            int  e=0;
          for(int i=1 ; i<=n ; i++)
          {
              if(a==-1)
              {
                  for(int j=9 ; j>=k[i-1]-48 ; j--)
                  {
                      ans=((ans-dp[n-i+1][j][e]+z)%z);
                  }

              }
              else
              {      for(int j=0 ; j<=k[i-1]-48 ; j++)
                      {
                          ans=((ans+dp[n-i+1][j][e])%z);
                      }
              }
             a=(-1*a);
             if(i!=n)
             e=((((e%d)-((k[i-1]-48)%d))+d)%d);
          }
         if(a==1)
         ans=((ans+dp[1][k[n-1]-48][e])%z);
         ans=((ans-1+z)%z);
        cout<<ans;

        }
