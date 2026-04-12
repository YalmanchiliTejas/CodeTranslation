#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,count,max;
  cin>>n;
  vector<int> a(n);
  count=max=0;
  for(int i=0;i<n;i++){
    cin>>a.at(i);

    if(a.at(i)>=max){
      count++;
      max=a.at(i);
    }
  }
  cout<<count<<endl;
}