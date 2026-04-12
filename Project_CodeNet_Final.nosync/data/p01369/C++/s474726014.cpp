#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
static const double EPS = 1e-8;
static const int INF = (int)1e8;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) for (int i=0; i<(int)(n); ++i)
string migis = "yuiophjklnm";
bool finds(char c){
  REP(i,migis.size())if(migis[i]==c)return true;
  return false;
}

int main(void){
  string input;
  while(cin>>input){
    int ans = 0;
    if(input=="#") break;
    int b = finds(input[0]);
    for(int i=1; i<input.size();i++){
      if(b!=finds(input[i]))ans++;
      b = finds(input[i]);
    }
    cout<<ans<<endl;
  }
  return 0;
}