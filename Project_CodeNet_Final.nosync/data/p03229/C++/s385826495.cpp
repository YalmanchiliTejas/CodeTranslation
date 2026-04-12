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
    
    
    priority_queue<int> q1,q2;
    int x,res1,res2;
    void solve()
    {
       cin>>n;
       fo(i,0,n)
       {
           cin>>x;
           q1.push(x);
           q2.push(-x);
       }
       
       if(n&1)
       {
           fo(i,0,n/2)
           {
               res1+=q1.top()*2;
               q1.pop();
               res2+=q2.top()*2;
               q2.pop();
           }
           
           res1-=q1.top();
           q1.pop();
           res1-=q1.top();
           q1.pop();
           res2-=q2.top();
           q2.pop();
           res2-=q2.top();
           q2.pop();
           
           fo(i,1,n/2)
           {
               res1-=q1.top()*2;
               q1.pop();
               res2-=q2.top()*2;
               q2.pop();
           }
           cout<<max(res1,res2)<<endl;
           
       }
       else
       {
           fo(i,1,n/2)
           {
               res1+=q1.top()*2;
               q1.pop();
           }
           res1+=q1.top();
           q1.pop();
           res1-=q1.top();
           q1.pop();
           fo(i,1,n/2)
           {
               res1-=q1.top()*2;
               q1.pop();
           }
           
           cout<<max(res1,res2)<<endl;
       }
 
        
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
