#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int> h(n);

  for (size_t i = 0; i < n; i++) {
    cin>>h[i];
  }
  
  int max = 0, count = 0;
  
  for (size_t i = 0; i < n; i++) {
    if(h[i]>=max){
      max = h[i];
      count++;
    }
  }

  cout<<count<<endl;
}
