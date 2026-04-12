

// Kachre ke dher ki bhi jagah badalti hai. Tum toh phir v insaan ho


#include <bits/stdc++.h>

#define ll                   long long int
#define MOD                  1000000007
#define fast()               ios_base::sync_with_stdio(false);  cin.tie(NULL);
#define fd(i,a,b)          for(ll i=(ll)a;i<(ll)b;i++)
#define bk(i,a,b)          for(ll i=(ll)a;i>=(ll)b;i--)
#define pb                   push_back
#define vi                   vector<ll>
#define test()               ll t; cin>>t; while(t--)
#define endl                 "\n"
#define param                greater<ll>()
#define ff                   first
#define ss                   second
#define all(v)               v.begin(),v.end()
#define mk                   make_pair
#define keep_unique(v) sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());
#define MAX 1000000000000000000

    // std::cout << std::setprecision(10) << std::fixed;

using namespace std;

const ll N = 1e5+10;

// struct compare {
//     bool operator()(const  pair < ll , ll > &a , const  pair < ll , ll > &b){
//         if(a.ff==b.ff)
//         return a.ss>b.ss;

//         return a.ff>b.ff;
//     }
// };


ll dp[3010][3010];






int main()
{

    fast()

    ll t;
    // cin>>t;
    t=1;

    while(t--)
    {
       ll i,j,a,b,c,d=0,n,k,x,y;
       
       string s, st;

        cin>>n;
        
        vector<ll>vec(n);
        
        for(i=0;i<n;i++)
        {
            cin>>vec[i];
            // vec[i]/=100;
        }
        
        ll sum=0;
        
        for(i=0;i<n;i++)
        {
           dp[i][i]=vec[i];
           sum+=vec[i];
        }
        
        for(i=0;i<n-1;i++)
        {
          dp[i][i+1]=max(vec[i],vec[i+1]);
        }
        
        
        for(j=2;j<n;j++)
        {
            
            for(i=0;i<n;i++)
            {
               
                   if(i+j>=n)break;
                   
                   dp[i][i+j]=max(vec[i]+min(dp[i+1][i+j-1],dp[i+2][i+j]) , vec[i+j]+min(dp[i][i+j-2],dp[i+1][i+j-1]) );
                   
                   
           
            }
            
        }
        
        
        // for(i=0;i<n;i++)
        // {
        //     for(j=0;j<n;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
         
        x=dp[0][n-1];
        y=sum-x;
        
        
        cout<<x-y;
        
        
        
       
        
        // for(i=0;i<=k;i++)
        // {
        //     cout<<pos[k]<<" ";
            
        // }
        
        // if(pos[k]==1)cout<<"First";
        // else cout<<"Second";
        
            
            // pair<ll,ll> res=pq.top();
       
            // cout<<res.ff;
            
            
       
       
       
       
        
        // sort(vec.begin(),vec.end());
        // reverse(vec.begin(),vec.end());
        
        // ll no=0;
        
        // cout<<vec[n-1]*vec[n-2]<<endl;
        
        // ll len=0,br=0;
        
        // for(i=0;i<n;i++)
        // {
            
          
            
        // }
        
        // cout<<sum;
        
        // if(no)
        // cout<<"NO"<<endl;
        // else
        // cout<<"YES"<<endl;
        
        
    //   dp[0][0]=1.0;
        
        // for(i=1;i<=n;i++)
        // {
        //     for(j=0;j<=i;j++)
        //     {
        //         if(j==0)
        //         dp[i][j]=dp[i-1][j]*(1.0-p[i]);
        //         else
        //         dp[i][j]=dp[i-1][j]*(1.0-p[i]) + dp[i-1][j-1]*p[i];
                
                
        //     }
        // }
        
       
   
        
       
       
       
       





    }

}

