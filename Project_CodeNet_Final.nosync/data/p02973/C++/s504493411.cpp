#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int> a(n);
  for (int i=0;i<n;++i) cin >> a[i];
  reverse(a.begin(),a.end());  
  vector<int> lab;
  int num=1;
  lab.push_back(a[0]);
  for (int i=1;i<n;++i) {
    if (lab[num-1]<=a[i]) {
      lab.push_back(a[i]);
      num+=1;
    } else if (lab[0]>a[i]) {
      lab[0]=a[i];
    } else {
      int j=0;
      while(a[i]>=lab[j]){
        j+=1;
      }
      lab[j]=a[i];
    }
  }
  cout<<num<<endl;
}

