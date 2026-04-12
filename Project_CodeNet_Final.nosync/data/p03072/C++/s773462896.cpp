#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int h;
  int maxh=0;
  int x=0;
  for(int i=0;i<n;i++){
      cin>>h;
      if(h >= maxh){
          x++;
          maxh=h;
      }
  }
  cout<<x<<endl;
}

