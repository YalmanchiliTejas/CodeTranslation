#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,now=0;
  cin >> n;
  long long a[n];
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  now=a[0];
  if(now<10){
    cout << "no" << endl;
    return 0;
  }
  for(int i=1;i<n;i++){
    if(now<10){
      cout << "no" << endl;
      return 0;
    }
    now=max(now-10LL,a[i]);
  }
  now=a[n-1];
  if(now<10){
    cout << "no" << endl;
    return 0;
  }
  for(int i=n-2;i>=0;i--){
    if(now<10){
      cout << "no" << endl;
      return 0;
    }
    now=max(now-10LL,a[i]);
  }
  cout << "yes" << endl;
  return 0;
}

