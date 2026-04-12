#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
#include <iomanip>
#include <stack>
using namespace std;
#define ll int64_t
const long mod = 1e9 + 7;


const long LINF = 1e13;
const long LLINF = 1e18;
const long ALPHABET = 26;

template <class T>
void Swap(T& r, T& l) {
  T tmp = r;
  r = l;
  l = tmp;
}

template<typename T>
istream& operator >> (istream& is, vector<T>& vec) {
  for (T& x : vec) is >> x; //for(int i=0; i<vec.size(); i++) is >> x[i]; とかでもいい
  return is;
}




int main() {

  long a, b;
  long n;
  cin >> n ;
  vector<long> h(n);

  cin >> h;


  long ans = 0;

  long tmp = -1;
  for(int i=0;i<n;i++){
    if (h[i]>=tmp){
      ans++;
      tmp=h[i];
    }
  }


  cout << ans << endl;

}


















