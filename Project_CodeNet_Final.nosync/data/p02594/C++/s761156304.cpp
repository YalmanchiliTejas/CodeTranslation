#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define MOD 1000000007
#define ll long long
#define int long long 
#define INF 1e18
#define ar array
#define f first
#define s  second
#define REP(i,n) for (int i=0;i<(n);i++)
#define wt(x) int x;cin>>x;while(x--)
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; 

void  c_p_c(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("input1.txt","r",stdin);

  freopen("output1.txt","w",stdout);
#endif
}

int power(int a,int b,int mod){
  a=a%mod;
  if(a==0){
    return 1;
  }
  int res=1;
  while(b){
    if(b&1){
      res=(res*a)%mod;
    }
    b>>=1;
    a=(a*a)%mod;
  }
  return res;
}

int  MMI(int p){
  return power(p,MOD-2,MOD);

}

int32_t main()
{
 c_p_c();
 int x;
 cin>>x;
 if(x>=30){
  cout<<"Yes\n";
 }
 else{
  cout<<"No\n";
 }




return 0;

}








   



   






