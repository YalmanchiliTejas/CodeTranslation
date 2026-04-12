#include<bits/stdc++.h>
using namespace std;

int main(){
  int i,n,flag=0;

  cin>>n;
  int num[n];
  for(i=0;i<n;i++){
    cin>>num[i];
  }

  int m = num[0];
  
  for(i=0;i<n;i++){
    if(num[i] >= m)
      flag++;

    m = max(m,num[i]);
  }

  cout<<flag<<endl;
  return 0;
}