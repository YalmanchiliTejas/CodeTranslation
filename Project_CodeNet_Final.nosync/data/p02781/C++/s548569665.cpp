#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int find(int i,int k)
{
   if(k>i||k<0||i<0)
      return 0;
   if(i==0)
      return 1;
   int ans=0;
       if(k==2)
         ans+=((i*(i-1))/2)*(pow(9,k));
      else if(k==1)
      {
         ans+=(i)*pow(9,k);
      }
      else
         ans++;  
   // cout<<ans<<'\n';
   return ans;
}

signed main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);  
//  #ifndef ONLINE_JUDGE
//     freopen ("INPUT.txt" , "r" , stdin);
//     freopen ("OUTPUT.txt" , "w" , stdout);
//  #endif
 
// -------------------------------------Code starts here---------------------------------------------------------------------     

   string s;
   cin>>s;
   int n=s.length();
   s="#"+s;
   int k;
   cin>>k;
   int ans=0;
   for(int i=k-1;i<=n-2;i++)
   {
      if(k==3)
         ans+=((i*(i-1))/2)*(pow(9,k));
      else if(k==2)
      {
         ans+=(i)*pow(9,k);
      }
      else
      {
         ans+=9;
      }      
   }
   // cout<<ans<<'\n';
   ans+=find(n-1,k-1)*(s[1]-'0'-1);
   // cout<<ans<<'\n';
   int cnt=1;
   for(int i=2;i<=n;i++)
   {
      if(s[i]-'0'!=0)
      {
         ans+=(s[i]-'0'-1)*find(n-i,k-cnt-1)+find(n-i,k-cnt);
         cnt++;
         // cout<<ans<<" ";
      }
   }
   if(cnt==k)
      ans++;
   cout<<ans;

// -------------------------------------Code ends here------------------------------------------------------------------
     clock_t clk;
 	clk = clock();
 
    clk = clock() - clk;
 	cerr << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
 	return 0;
 }
