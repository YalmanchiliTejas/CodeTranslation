#include<iostream>
using namespace std;
int main(){
  while(true){
    int n;
    int sum=0;
    int mx=0;
    int mn=1001;
    cin >>n;
    if(n==0)break;
    for(int i =0;i<n;++i){
      int t;
      cin >> t;
      sum += t;
      mx = max(t,mx);
      mn = min(t,mn);
    }
    sum = (sum-mx-mn) / (n-2);
    cout << sum << endl;
  }
  return 0;
}