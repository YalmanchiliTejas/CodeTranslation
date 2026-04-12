#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int N;
  cin >> N;
  int X[N+1],Y[N+1];
  int m=N/2,i;
  for (i=1;i<=N;++i) {
    cin >> X[i];
    Y[i]=X[i];
  }
  sort(Y+1, Y+(N+1));
  //Y[m]かY[m+1]
  for (i=1;i<=N;++i) {
    if (X[i]<=Y[m]) {
      cout << Y[m+1] << endl;
    } else {
      cout << Y[m] << endl;
    }
  }
  return 0;
}
