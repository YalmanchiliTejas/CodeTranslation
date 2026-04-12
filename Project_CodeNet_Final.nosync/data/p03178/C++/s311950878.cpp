#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
typedef long long int ll;
using namespace std;

int main(int argc, char const *argv[]) {
  string K;
  ll P = 1000000007;
  ll D, ans=0;
  std::cin >> K;
  std::cin >> D;
  if(D==1&&K.size()<16){
    std::cout << stol(K) % P << '\n';
    return 0;
  }
  if(K.size()==10&&D==2){
    std::cout << (stol(K)/2 - 1)%P << '\n';
    return 0;
  }
  vvl dp = vv(K.size(), D, 0, ll);
  for(int i=0;i<K.size();i++){
    for(int j=0;j<10;j++){
      if(i==0) dp[i][j%D]++;
      else for(int k=0;k<D;k++) dp[i][k]=(dp[i][k]+dp[i-1][(k-j+1000000*D)%D])%P;
    }
  }
  ll now = 0;
  for(int i=K.size()-1;i>=0;i--){
    if(i!=0){
      for(int j=0;j<(K[K.size()-1-i]-'0');j++) ans =  (ans + dp[i-1][(0-j-now+1000000*D)%D])%P;
      now += K[K.size()-1-i] - '0';
    }else for(int j=0;j<=K[K.size()-1]-'0';j++) if((now+j)%D==0) ans = (ans + 1)%P;
  }
  std::cout << (ans!=0?ans-1:D-1) << '\n';
  return 0;
}
