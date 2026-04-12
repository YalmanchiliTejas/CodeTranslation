//-------All power is within you,you can do Anything and Everything.---------//
 
    #include <bits/stdc++.h>
    using namespace std;
  
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ M $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
 
    #define pb push_back
    #define MP make_pair
    #define F first
    #define S second
    #define int long long
    #define fo(i,a,b) for(int i=a;i<b;i++)
    #define rfo(i,b,a) for(int i=b;i>=a;i--)
    #define deb(x) cout<<#x<<" "<<x<<endl;
    #define mem( a, val ) memset(a, val, sizeof( a ) )
    #define deci( x ) cout<<fixed<<setprecision( x );
    #define bitcount( x ) __builtin_popcountll( x )
 
    
    typedef vector<int> vi;
    typedef pair<int,int> pi; 
    
    const int MOD =  1000000007 ;
    const int MAX = 2e6 + 7;
    const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
 
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ V $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//  
    
    int i,j,k,t,n,q,l,r,mid;
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ F $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
    
    
    int x,ans,res;
    int a[MAX];
    
    void solve()
    {
       cin>>n;
       fo(i,1,n+1)
       {
           cin>>a[i];
       }
       
       sort(a+1,a+n+1);
       
       l=1;
       r=n;
       x=a[(n+1)/2];
       fo(i,1,n)
       {
           if(i&1)
           {
               ans+=abs(a[l]-x);
               x=a[l++];
           }
           else
           {
               ans+=abs(a[r]-x);
               x=a[r--];
           }
       }
       
       l=1;
       r=n;
       x=a[(n+1)/2];
       fo(i,1,n)
       {
           if(!(i&1))
           {
               res+=abs(a[l]-x);
               x=a[l++];
           }
           else
           {
               res+=abs(a[r]-x);
               x=a[r--];
           }
       }
       cout<<max(res,ans)<<endl;
       
       
        
    }
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
//                          GAME STARTS FROM HERE                            //
 
    int32_t main() 
      {
        
        // int start,stop=clock();
        // cout<<"time:"<<(stop-start)/double(CLOCKS_PER_SEC)*1000<<endl;
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        
        // cin>>t;while(t--)
        solve();
        
      return 0;
      }
