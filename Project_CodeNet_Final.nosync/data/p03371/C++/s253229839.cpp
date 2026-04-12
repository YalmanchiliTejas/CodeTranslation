#include<bits/stdc++.h>
using namespace std;
typedef long long int llint;
typedef long int lint;
typedef vector<char> vchar;
typedef vector<int> vint;
typedef vector<vector<int>> vvint;
typedef vector<vector<char>> vvchar;
#define vsort(v) sort((v).begin(), (v).end())
#define vreverse(v) reverse((v).begin(), (v).end())
#define pb(a) push_back(a)
#define INF 1000000007
int main(){
  lint a,b,c,x,y;llint ans;llint pa,pb;
  cin>>a>>b>>c>>x>>y;
  if(a+b<=c*2){ans=a*x+b*y;}
  else{
  pa=2*c*max(x,y);
  if(x>y){pb=c*y*2+a*(x-y);}else{pb=2*c*x+b*(y-x);}
  ans=min(pa,pb);
  }
  cout<<ans<<endl;
}
