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
typedef unsigned long long int ll;
using namespace std;

int main(int argc, char const *argv[]) {
  ll N, S=0, ans = 0;
  std::cin >> N;
  bool flag = false;
  std::vector<ll> A(N);
  for(int i=0;i<N;i++){
    std::cin >> A[i];
    if(A[i]>10000) {
      flag = true;
      ll tmp = A[i];
      if(A[i]>=51*(N+1))A[i] = (A[i]%(51*(N+1))==0?(51*(N+1)):A[i]%(51*(N+1)));
      S+=tmp-A[i];
    }
  }
  if(flag){
    while(true){
      ll ma=N-1, mai=-1;
      for(int i=0;i<N;i++) if(ma<A[i]) ma=A[i], mai=i;
      if(mai==-1) break;
      ans++;
      for(ll i=0;i<N;i++) {
        if(i==mai) A[i]-=N;
        else A[i]++;
      }
    }
    std::cout << S + ans << '\n';
  }else{
    while(true){
      ll ma=N-1, mai=-1;
      for(ll i=0;i<N;i++) if(ma<A[i]) ma=A[i], mai=i;
      if(mai==-1) break;
      ans++;
      for(ll i=0;i<N;i++) {
        if(i==mai) A[i]-=N;
        else A[i]++;
      }
    }
    std::cout << ans << '\n';
  }
  return 0;
}
