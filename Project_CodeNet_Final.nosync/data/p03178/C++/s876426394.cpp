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
#define MOD 1000000007
ll dp[10001][100][2];

int main(){
    std::ios::sync_with_stdio(false);

    string s;
    int d;
    cin >> s >> d;

    dp[0][0][0] = 1;
    for(int i=0;i<s.length();++i)
    {
      for(int j=0;j<d;++j)
      {
        for(int k=0;k<10;++k)
        {
          int digit = s[i] - '0';
          if(k < digit)
          {
            dp[i+1][(j+k) % d][1] += (dp[i][j][0] + dp[i][j][1]);
            dp[i+1][(j+k) % d][1] %= MOD;
          }else if(k == digit)
          {
            dp[i+1][(j+k) % d][0] += dp[i][j][0];
            dp[i+1][(j+k) % d][1] += dp[i][j][1];
            dp[i+1][(j+k) % d][0] %= MOD;
            dp[i+1][(j+k) % d][1] %= MOD;
          }else
          {
            dp[i+1][(j+k) % d][1] += dp[i][j][1];
          }
        }
      }
    }
    cout << (dp[s.length()][0][0] + dp[s.length()][0][1] - 1) % MOD << endl;
}