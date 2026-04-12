#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t n;
  cin>>n;
  vector<int64_t> a(n);
  vector<int64_t> b(n);
  for(int i=0;i<n;i++){
    cin>>a.at(i);
  }
  if(n%2==0){
    for(int i=0;i<n/2;i++){
      b.at(i)=a.at(n-1-2*i);
    }
    for(int i=n/2;i<n;i++){
      b.at(i)=a.at((i-n/2)*2);
    }
  }
  else{
    for(int i=0;i<n/2;i++){
      b.at(i)=a.at(n-1-2*i);
    }
    b.at(n/2)=a.at(0);
    for(int i=n/2+1;i<n;i++){
      b.at(i)=a.at(1+2*(i-n/2-1));
    }
  }
  for(int i=0;i<n;i++){
    cout<<b.at(i)<<endl;
  }
}