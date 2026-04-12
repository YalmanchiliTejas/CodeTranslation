#include <iostream>
#include <algorithm>
using namespace std;

int d[300005];
int main() {
  int N;
  cin >> N;
  for(int i=0; i<N; i++) cin >> d[i];
  for(int i=0; i<2; i++) {
    int a=0;
    for(int j=0; j<N; j++) {
      if(a<j*10){
        cout << "no" << endl;
        return 0;
      }
      a=max(a, j*10+d[j]);
    }
    reverse(d, d+N);
  }
  cout << "yes" << endl;
}