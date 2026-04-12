#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,count=0;
  cin>>n;
  vector<int> num(n);
  for(int i=0;i<n;i++){
    cin>>num[i];
    int c=0;
    while(num[i]>=num[c]){
      c++;
      if(c>i) break;
    }if(c==i+1){
      count++;
    }
  }
  cout<<count<<endl;
}