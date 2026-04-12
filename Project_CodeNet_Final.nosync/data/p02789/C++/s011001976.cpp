#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int power(int x, unsigned int y, int p) 
{ 
    int res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or  
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p;   
    } 
    return res; 
} 
int mx[1000005];
int fr[1000005];
int mod=1e9+7;
signed main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);  
//  #ifndef ONLINE_JUDGE
//     freopen ("INPUT.txt" , "r" , stdin);
//     freopen ("OUTPUT.txt" , "w" , stdout);
//  #endif

// -------------------------------------Code starts here---------------------------------------------------------------------     

   int n,m;
   cin>>n>>m;
   if(n==m)
   {
      cout<<"Yes";
   }
   else
   {
      cout<<"No";
   }
   

// -------------------------------------Code ends here------------------------------------------------------------------
     clock_t clk;
 	clk = clock();
 
    clk = clock() - clk;
 	cerr << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
 	return 0;
 }