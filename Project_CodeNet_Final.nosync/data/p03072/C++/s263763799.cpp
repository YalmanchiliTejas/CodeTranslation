#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int sum =1;
  int m =0;
  vector<int> h(n);
  for(int i=0;i<n;i++)
    cin >> h[i];
  
  for(int i=1;i<n;i++){
    m = max(m,h[i-1]);
    if(h[i]-m>=0)
      sum++;
  }
  cout << sum << endl;
}