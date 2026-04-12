#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define loop(i,x,n) for(int i=(x);i<(n);i++)
#define all(v) (v).begin(),(v).end()
//#define int long long
using namespace std;
const int MOD=1e9+7;
//const int INF=1e10;

using namespace std;
int main(){
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  int ans=a*x+b*y;
  //cout<<ans<<endl;
  for(int i=0;i<200001;i+=2){
    int tmp_x=x-i/2;
    int tmp_y=y-i/2;
    int sum=a*max(tmp_x,0)+b*max(tmp_y,0)+c*i;
    ans=min(ans,sum);
  }
  cout<<ans<<endl;
  return 0;
}
