#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define PB push_back
#define MP make_pair
#define ll long long

#define FILL(ptr, value) FILL_((ptr), sizeof(ptr)/sizeof(value), (value))
 
template <typename T>
void FILL_(void * ptr, size_t size, T value){
  std::fill((T*)ptr, (T*)ptr+size, value);
}
 

inline int toInt(string s){int v;istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x){ostringstream sout;sout<<x;return sout.str();}

ll dp[3002][3002] = {};

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int a[n] = {};
    for(int i=0;i<n;++i)
    {
      cin >> a[i];
    }

    for(int i=0;i<n;++i)
    {
      dp[i][i+1] = 0; // [i, j) = 0;
    }

    for(int l=0;l<n;++l)
    {
      for(int i=0;i<n;++i)
      {
        if(i+l+1 > n)
        {
          break;
        }

        int turn = (n - (l + 1)) % 2;
        if(turn == 0)
        {
          // maximize X - Y
          dp[i][i+l+1] = max(dp[i+1][i+l+1] + a[i], dp[i][i+l] + a[i+l]);
        }
        else
        {
          // minimize X - Y
          dp[i][i+l+1] = min(dp[i+1][i+l+1] - a[i], dp[i][i+l] - a[i+l]);
        }
      }
    }

    cout << dp[0][n] << endl;
}