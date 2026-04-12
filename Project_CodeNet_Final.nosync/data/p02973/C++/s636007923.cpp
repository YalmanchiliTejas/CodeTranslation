#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <bitset>
#include <tuple>
#include <set>
#include <map>
#define range(i, r) for(int i=0;i<r;i++)
#define ranges(i, l, r) for(int i=l;i<r;i++)
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
#define MODn 1000000009;
typedef long long int ll;
using namespace std;

int main(int argc, char const *argv[]) {
  int N;
  std::cin >> N;
  std::vector<int> A(N+1);
  multiset<int> num;

  for(int i=1;i<=N;i++) {
    std::cin >> A[i];
  }
  num.insert(A[1]);
  for(int i=2;i<=N;i++){
    if(A[i]<=*num.begin()){
      num.insert(A[i]);
    }else{
      auto itr = num.lower_bound(A[i]);
      itr--;
      num.insert(A[i]);
      num.erase(itr);
    }
  }
  std::cout << num.size() << '\n';
  return 0;
}
