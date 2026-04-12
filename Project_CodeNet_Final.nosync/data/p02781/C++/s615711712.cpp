#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
using lint=long long;
using pint=pair<int,int>;
template<class T> using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

lint dp[110][2][10];

int main()
{
   string s; cin>>s;
   int K; cin>>K;
   int N=s.size();

   dp[0][0][0]=1;
   for(int i=0;i<N;i++) for(int less=0;less<2;less++) for(int j=0;j<=K;j++){
      int maxD=(less? 9:s[i]-'0');
      for(int d=0;d<=maxD;d++){
         dp[i+1][less|(d<s[i]-'0')][j+(d!=0)]+=dp[i][less][j];
      }
   }
   cout<<dp[N][0][K]+dp[N][1][K]<<endl;
   return 0;
}
