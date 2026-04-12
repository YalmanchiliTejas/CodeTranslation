    #pragma GCC optimize("Ofast")
    #pragma GCC optimize("unroll-loops")
    #pragma GCC target("sse2")
 
    #include <bits/stdc++.h>
    #include <vector> 
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    using namespace std;
 
    #define int         long long
    #define ll          long long
    #define pb          push_back
    #define pii         pair<int,int>
    #define vi          vector<int>
    #define vii         vector<pii>
    #define mi          map<int,int>
    #define mii         map<pii,int>
    #define mp          make_pair
    #define all(a)      (a).begin(),(a).end()
    #define FF           first
    #define SS           second
    #define sz(x)       (int)x.size()
    #define endl        '\n'
    #define rep(i,a,b)  for(int i=a;i<b;i++)
     ll hell=1000000007;



   
  
    int solve(){  
      
          int n,x,m;
          cin>>n>>x>>m;
          int sum=0;
          int a[m+1]={0},k=0;
          vi val;
          while(true)
          {  
            if(a[x]==1)break;
            sum+=x;
            k++;
            if(k==n)
                return cout<<sum<<endl,0;
            val.pb(x);
            a[x]=1;
            x=(x*x)%m;
          }
          n-=k;
          int ans=sum;
          sum=0;
          val.clear();
          memset(a,0,sizeof(a));

            while(true)
          {  
            if(a[x]==1)break;
            sum+=x;
            k++;
            if(k==n)
                return cout<<sum<<endl,0;
            val.pb(x);
            a[x]=1;
            x=(x*x)%m;
          }



          int n1=val.size();
          ans+=sum*(n/n1);
          n%=n1;
          rep(i,0,n)ans+=val[i];
          cout<<ans<<endl;




     return 0;
        
        }


    signed main()
    {       


 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0); 
 
    int t=1,k=1;                                                                                                                  
    //cin>>t;
   
    while(t--)
    {
     
     // cout<<"Case #"<<k++<<": ";
     solve();
     //cout<<endl;
    }
    return 0;
    } 