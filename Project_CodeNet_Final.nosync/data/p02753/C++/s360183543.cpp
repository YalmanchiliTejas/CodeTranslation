#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



signed main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);  
   
 #ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
    freopen ("INPUT.txt" , "r" , stdin);
    freopen ("OUTPUT.txt" , "w" , stdout);
    }
 #endif

// -------------------------------------Code starts here---------------------------------------------------------------------     

   string a;
   cin>>a;
   int n=a.length();
   int cnt=0;
   for(int i=0;i<n;i++)
   {
      if(a[i]=='A')
         cnt++;
   }
   if(cnt>0 && n-cnt>0)
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
