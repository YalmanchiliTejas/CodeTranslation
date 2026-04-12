#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <iomanip>
#include <string.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()

typedef long long lint;

using namespace std;

int main(){
  string S;
  cin>>S;
  set<char> s;
  for(auto c:S){
    s.insert(c);
  }
  cout<<(s.size()>=2?"Yes":"No")<<endl;
  return 0;
}
