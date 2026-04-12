#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
#define MAX 100005
using Graph=vector<vector<int>>;

int main(){
  int A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;
  int ans=A*X+B*Y;
  ans=min(ans,2*C*X+B*max(0,Y-X));
  ans=min(ans,2*C*Y+A*max(0,X-Y));
  cout<<ans<<endl;
}
