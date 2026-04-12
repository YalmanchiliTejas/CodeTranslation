    // In the name of Allah
    // There is no power but from God the Almighty
   // No God except Allah
   #include <bits/stdc++.h>
   #define mp make_pair
   #define f1 first
   #define f2 second
   #define pb push_back
   #define pii pair<int ,int>
   #define ios  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   using namespace std;
   const int mox=1e5+9;
   vector<int> v[mox];
   bool ok[mox];
   bool ans;
   void dfs(int x ,int dad=-1)
   {
       for(int i:v[x])
       {
          if(i!=dad)
          {
            dfs(i,x);
          }
       }
       if(!ok[x])
       {
         if(dad==-1)
         {
            ans=1;
         }
         else if(!ok[dad])
         {
           ok[dad]=1;
           ok[x]=1;
         }
         else
         {
           ans=1;
         }
       }
   }
   main()
   {
    int n;
    cin>>n;
    for(int i=0 ; i<n-1 ; i++)
     {
       int a,b;
       cin>>a>>b;
       v[a].pb(b);
       v[b].pb(a);
     }
     dfs(1);
     if(ans)
     {
       cout<<"First";
     }
     else
     {
       cout<<"Second";
     }
   }
