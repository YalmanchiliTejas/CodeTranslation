   #include<bits/stdc++.h>
   using namespace std;
   vector<int> l[100005];
   int dp[100005];
   int visited[100005];
   long long int mod=1000000000+7;
  int main()
  {   
     long long int n;
     cin>>n;
     long long int a[n];

     for(int i=0;i<n;i++)
      cin>>a[i];

     pair<long long int,long long int> dp[n][n]; 
     for(int i=0;i<n;i++)
     {
        dp[i][i].first=a[i];
        dp[i][i].second=0;
     }
     for(int i=0;i<n-1;i++)
     {
        dp[i][i+1].first=max(a[i],a[i+1]);
        dp[i][i+1].second=min(a[i],a[i+1]);
     }
    for(int l=3;l<=n;l++)
    {
       for(int i=0;i<n-l+1;i++)
       {
          int j=i+l-1;
          
          if(a[i]+dp[i+1][j].second < a[j]+dp[i][j-1].second)
          {
             dp[i][j].first =a[j]+dp[i][j-1].second;
             dp[i][j].second=dp[i][j-1].first;
          }
          else
          {
             dp[i][j].first =a[i]+dp[i+1][j].second;
             dp[i][j].second=dp[i+1][j].first;
          }
       }
    }
   //  for(int i=0;i<n;i++)
   //  {
   //     for(int j=0;j<n;j++)
   //     {
   //        cout<<"("<<dp[i][j].first<<" ,"<<dp[i][j].second<<" ) ";
   //       }
   //       cout<<"\n";

   //  }

     cout<<dp[0][n-1].first-dp[0][n-1].second;

   
  }

