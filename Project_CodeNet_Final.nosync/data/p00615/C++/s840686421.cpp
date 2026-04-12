#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int gtime[30000];
int ttime[30000];

struct comp{
  bool operator()(const int &x, const int &y)const{
    return (x > y);
  }
};

int main()
{
  while (true) {
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0) {break;}
    
    gtime[0] = 0;
    for (int i = 1; i <= n + m; i++){
      cin >> gtime[i];
    }
    sort(gtime, gtime + n + m + 1);
    for (int i = 0; i < n + m; i++) {
      ttime[i] = abs(gtime[i] - gtime[i + 1]);
      //cout << i << " " << ttime[i] << endl;
    }
    //if (n + m - 1 == 0) ttime[0] = gtime[0];
    sort(ttime, ttime + (n + m), comp());
    cout << ttime[0] << endl;
  }
  
  return 0;
}