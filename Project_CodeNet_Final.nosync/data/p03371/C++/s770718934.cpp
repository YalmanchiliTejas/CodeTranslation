#include "bits/stdc++.h"
#define st string
#define int long long
#define mii map<int,int>
#define low lower_bound
#define upp upper_bound
#define mod 1000000007 //10^9+7
#define rep(i,n) for(int i=0;i<n;i++)
#define all(vec) vec.begin(),vec.end()
#define sort(vec) sort(all(vec));
#define rever(vec) reverse(all(vec));
#define bisea binary_search
#define unsort(vec) sort(vec); rever(vec);
#define cend cout<<endl;
#define gcd __gcd
using namespace std;
signed main() {
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  int sum=0;
  int d=abs(x-y);
  sum+=min(x,y)*min(a+b,2*c);
  if(x>y) sum+=min(a*d,d*2*c);
  else sum+=min(b*d,d*2*c);
  cout<<sum<<endl;
}