#include <iostream>
using namespace std;

#define N 300000
#define MAX(X,Y) ((X)>(Y)?(X):(Y))
int main(void){
  int n;
  int d[N], dmax;
  
  cin >> n;
  for (int i=0; i<n; i++) cin >> d[i];
  // L->R
  dmax = 0;
  for (int i=0; i<n; i++){
    if (dmax<10*i){
      cout << "no" << endl;
      return 0;
    }
    dmax = MAX(dmax, 10*i+d[i]);
  }
  // L <- R
  dmax = 0;
  for (int i=0; i<n; i++){
    if (dmax<10*i){
      cout << "no" << endl;
      return 0;
    }
    dmax = MAX(dmax, 10*i+d[n-1-i]);
  }
  cout << "yes" << endl;
  return 0;
}
