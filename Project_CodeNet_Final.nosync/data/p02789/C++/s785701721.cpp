#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <cmath>
#include <stack>

using namespace std;
using ll = long long int;

template <class T> ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto i = v.begin(); i != v.end(); i++) {
    os << *i << " ";
  }
  return os;
}

const string YES = "Yes";
const string NO = "No";

void solve(long long N, long long M){
  if(N==M)
    std::cout << YES << std::endl;
  else
    std::cout << NO << std::endl;
}

int main(){
  long long N;
  scanf("%lld",&N);
  long long M;
  scanf("%lld",&M);
  solve(N, M);
  return 0;
}

