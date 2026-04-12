#include <iostream>
#include <vector>
#include <bitset>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
 
using namespace std;
typedef long long ll;
 
const ll MOD=1000000007;

int main(){
  string K;
  int D;
  cin >> K >> D;

  int d=K.size();

  vector<vector<ll>> p(d+1,vector<ll>(D,0));
  p[0][0]=1;
  for (int i = 1; i < d+1; i++){
    //cout << i << ":";
    for (int j = 0; j < D; j++){
      for (int k = 0; k < 10; k++){
        p[i][j]+=p[i-1][((j-k)%D+D)%D];
        p[i][j]%=MOD;
      }
      //cout << p[i][j] << " ";
    }
    //cout << endl;
  }

  ll ans=0;
  ll s=0;  
  for(int i=0;i<d;i++){
    for(int j=0;j<(K[i]-'0');j++){
      ans+=p[d-i-1][(D-(s+j)%D)%D];
      ans%=MOD;
    }
    s+=K[i]-'0';
  }

  if(s%D==0) ans++;

  cout << (ans-1+MOD)%MOD << endl;

  return 0;
}
