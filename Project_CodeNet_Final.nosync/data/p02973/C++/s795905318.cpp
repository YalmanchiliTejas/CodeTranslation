
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <numeric>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)


int main() {

  int N;
  cin >> N;

  vector<int> A(N);
  vector<P> V;
  int l = 0;
  int r = 0;
  REP(i, N) {
    cin >> A[i];
  }
  vector<int> B;

  B.push_back(A[N - 1]);

  for(int i = N - 2; i >= 0; i--){
    if (A[i] >= *(B.end() - 1)) B.push_back(A[i]);
    else{
      *upper_bound(B.begin(), B.end(), A[i]) = A[i];
    }
    //for(auto tmp : B) cout << tmp;
    //cout << endl;
  }

  cout << B.size() << endl;




  return 0;
}
