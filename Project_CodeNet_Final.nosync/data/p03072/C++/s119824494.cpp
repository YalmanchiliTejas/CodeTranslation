#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,h[29];
  cin >> n;
  for(int i=0; i<n; i++) cin >> h[i];
  int sum=1;
  int high=h[0];
  for(int i=1; i<n; i++){
    if(h[i]>=high){
      sum++;
      high=h[i];
    }
  }
  cout << sum << endl;
}