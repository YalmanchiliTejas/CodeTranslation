#include <bits/stdc++.h>
using namespace std;
int main(){
int n,count=0;
  cin >>n;
  int h[n];
  for(int i=0;i<n;i++)cin >>h[i];
  for(int i=0;i<n;i++){
    bool ok=true;
    for(int j=0;j<i;j++){
      if(h[i]<h[j])ok=false;
    }
    if(ok)count++;
  }
  cout <<count<<endl;
}