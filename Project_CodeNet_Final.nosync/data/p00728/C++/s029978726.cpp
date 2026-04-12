#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

int main() {
  int n;
  while(cin>>n,n) {
    vector<int> v(n);
    REP(i,n)
      cin >> v[i];
    v.erase(max_element(ALL(v)));
    v.erase(min_element(ALL(v)));
    int sum = 0;
    FOR(i,v) {
      sum+=*i;
    }
    cout << sum/v.size() << endl;
  }
}