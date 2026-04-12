#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define LOOP(i,x,n) for(int i=x;i<n;i++)
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define MP make_pair
#define FIR first
#define SEC second
#define int long long
using namespace std;
const int MOD=1000000007;
const int INF=1000000009;

signed main(){
  int x,y,z;
  cin>>x>>y>>z;
  int ans=0;
  int tmp=0;
  LOOP(i,1,100000){
    if(i*y+(i+1)*z<=x){
      ans=max(ans,i);
    }
  }
  cout<<ans<<endl;
  return 0;
}
