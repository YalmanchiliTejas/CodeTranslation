#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<sstream>
#include<cmath>
#include<numeric>
#include<map>
#include<stack>
#include<queue>
using namespace std;
int inf = 1000000000;

int main(void) {

  vector< pair<int, int> > p;
  pair<int, int> t;
  while( true ){
    scanf("%d,%d", &t.second, &t.first);
    if( t.first == 0 && t.second == 0 ) break;
    p.push_back(t);
  }
  sort(p.begin(), p.end());
  vector<int> ans(101, 0);
  int n = 1;
  ans[ p[p.size()-1].second ] = n;
  for(int i=p.size()-2; i>=0; i--){
    if( p[i].first == p[i+1].first ){
      ans[ p[i].second ] = n;
    }else{
      n++;
      ans[ p[i].second ] = n;
    }
    // cerr << ans[ p[i].second ] << endl;
  }
  int a;
  while( scanf("%d", &a) != EOF ){
    cout << ans[a] << endl;
  }

  return 0;
}

// EOF