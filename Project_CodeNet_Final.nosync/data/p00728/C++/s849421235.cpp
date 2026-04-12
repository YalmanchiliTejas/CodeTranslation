#include<iostream>
using namespace std;

int main() {
  int n,s,total,max,min;
  while(cin>>n, n) {
    cin>>s;
    max = min = total = s;
    for(int i=0; i<n-1; ++i) {
      cin>>s;
      if(s < min) min = s;
      if(s > max) max = s;
      total += s;
    }
    total = total - min - max;
    cout<<total/(n-2)<<endl;
  }
}