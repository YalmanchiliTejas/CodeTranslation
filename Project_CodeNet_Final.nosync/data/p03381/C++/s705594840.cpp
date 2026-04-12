#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int>x(n), xs;
  for(int i=0; i<n; i++)cin >> x[i];
  xs = x;
  sort(xs.begin(), xs.end());
  for(int i=0; i<n; i++){
    if(x[i]<=xs[n/2-1])cout << xs[n/2] << endl;
    else cout << xs[n/2-1] << endl;
  }
  return 0;
}