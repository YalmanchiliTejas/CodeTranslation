#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
  int a,b,c,x,y;
  // vector<int> m;

  cin >>a>>b>>c>>x>>y;
  // for (int i = 0; i < n; ++i) {
  //   cin >> mt;
  //   m.push_back(mt);
  // }
  // for (auto l:m) {
  //   cout<<l<<endl;
  // }
  vector<int> p;
  int na=0, nb=0, nc=0;
  int big = (x>y) ? x : y;

  


  c=c*2;
  int value,rx,ry;
  for (int i=0; i <= big; ++i) {
    rx = (x>=i) ? (x -i): 0;
    ry = (y>=i) ? (y -i) : 0;
    value= rx * a + ry * b + i * c;
    p.push_back(value);
  }

  
  int minn = *min_element(p.begin(), p.end());
  cout<<minn<<endl;
}

