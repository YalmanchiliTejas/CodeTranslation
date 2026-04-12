#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef vector<int,vector<int>> vec;
typedef pair<string,int> P;
#define REP(i,j,n) for (int i=j;i<(n);i++)
#define RREP(i,n,j) for (int i = n; j<i;i--)
#define print(out) cout<< out  << "\n";
#define all(vec) vec.begin(),vec.end()
#define mod 1000000007
const int INF = 1e9;

int main(){
  int A,B,C,X,Y;cin>>A>>B>>C>>X>>Y;
  int AB_price=min(A+B,2*C);
  int ans=0;
  if(X>Y){
    ans=Y*AB_price+(X-Y)*A;
  }
  else{
    ans=X*AB_price+(Y-X)*B;
  }
  ans=min(ans,max(X,Y)*AB_price);
  print(ans)
}
