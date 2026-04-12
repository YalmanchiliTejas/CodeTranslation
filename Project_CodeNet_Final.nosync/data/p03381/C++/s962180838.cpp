#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> x(N);
  vector<int> y(N);
  for(int i=0;i<N;i++){
    cin >> x[i];
  }
  copy(x.begin(),x.end(),y.begin());
  sort(y.begin(),y.end());
  int s,l;
  s=y[N/2-1];
  l=y[N/2];
  for(int i=0;i<N;i++){
    if(x[i]<=s)cout << l << endl;
    else cout << s << endl;
  }
}


