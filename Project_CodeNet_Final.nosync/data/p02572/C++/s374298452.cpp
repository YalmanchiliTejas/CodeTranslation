#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#define _GLIBCXX_DEBUG
#define INF 100000010
 #define PI 3.14159265359

using namespace std;
const int64_t mod = 1000000007;
const int64_t tmpMod = 998244353;

int main() {
 
  int64_t N,sum=0,ans=0;
  cin>>N;
  vector<int64_t> A(N);
  for(int i=0; i<N; i++){cin>>A[i];sum+=A[i];}
  for(int i=0; i<N; i++){
    sum-=A[i];
    ans+=(A[i]*(sum%mod));
    ans%=mod;
    
    }
  //vector<vector<int> > A(N,vector<int>(M));
  //for(int i=0; i<N; i++){
  //   for(int j=0; j<M; j++){
  //       cin>>A[i][j];
  //   }
  // }
  //sort(A.begin(),A.end());
  //for (int i = 0; i < N; i++) { maximum = max(maximum , A[i]);}
  //for (int i = 0; i < N; i++) { minimum = min(minimum , A[i]);}
  // cout << ans/2 << endl;
  cout << ans%mod << endl;
}