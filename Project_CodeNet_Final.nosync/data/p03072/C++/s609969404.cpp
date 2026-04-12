#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> h(n);
  for (int i=0;i<n;i++){
    cin >> h[i];
  }
  int count=1;
  int a=h[0];
  for (int i=1;i<n;i++){
    if(h[i]>=a){
      count++;
      a=h[i];
    }
  }
  cout << count << endl;
}