  #include <bits/stdc++.h>
  using namespace std;
  #define int long long int
  #define vi vector<int>
  #define pii pair<long long ,long long>
  #define pll pair<int,int>
  #define mod 1000000007
  #define hell 998244353
  #define all(x) x.begin(),x.end()
  #define mp(x,y) make_pair(x,y)
  #define mem(a,val) memset(a,val,sizeof(a))
  #define eb push_back
  #define ff first
  #define ss second
  #define rep(n) for(int i=0;i<n;i++)
  #define lb lower_bound
  #define up upper_bound
  int dp[3005][3005];
  void solve()
  { 
     
     int n;
     cin>>n;
     int sum=0;
     vi v(n);
     rep(n)
      {cin>>v[i];
       sum+=v[i];
      }

      for(int gap=0;gap<n;gap++)
      {
         for(int i=0,j=gap;j<n;i++,j++)
         {
              // f(i,j)=max(vi,min(f(i+2,j),f(i+1,j-1)),vj+min(f(i+1,j-1),f(i,j-2)))
           
            int x=i+2<=j?dp[i+2][j]:0;
            int y=i+1<=j-1?dp[i+1][j-1]:0;
            int z=i<=j-2?dp[i][j-2]:0;

            dp[i][j]=max(v[i]+min(x,y),v[j]+min(y,z));            
         }
      }

      cout<<dp[0][n-1]-(sum-dp[0][n-1]);



   

  






  }



  signed main()
  {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


   
    
    
    int T;
    T=1;
    
    while(T--)
    {
      solve();
    }
    return 0;
  }