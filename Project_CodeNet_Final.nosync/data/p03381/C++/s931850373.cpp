#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t n;
  cin>>n;
  vector<int64_t> x(n);
  vector<int64_t> y(n);
  for(int64_t i=0;i<n;i++){
    cin>>x.at(i);
    y.at(i)=x.at(i);
  }
  sort(y.begin(),y.end());
  int64_t mid1=y.at(n/2-1),mid2=y.at(n/2);
  for(int64_t i=0;i<n;i++){
    if(x.at(i)<mid1){
      cout<<mid2<<endl;
      continue;
    }
    if(x.at(i)>mid2){
      cout<<mid1<<endl;
      continue;
    }
    if(x.at(i)==mid1){
      cout<<mid2<<endl;
      continue;
    }
    if(x.at(i)==mid2){
      cout<<mid1<<endl;
    }
  }
}