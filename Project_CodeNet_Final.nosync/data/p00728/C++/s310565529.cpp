#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  while(1){
    cin >> n;
    if(n==0){
      break;
    }
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n;i++){
      cin >> a[i];
      sum += a[i];
    }
    sort(a.begin(), a.end());
    sum-=a[n-1];
    sum-=a[0];
    cout << sum / (n - 2) << endl;
  }
  return 0;
}
