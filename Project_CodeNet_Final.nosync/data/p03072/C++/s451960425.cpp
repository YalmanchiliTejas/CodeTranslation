#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  	cin>>n;
  vector<int>vec(n);
  for(int i=0;i<n;i++){
    cin>>vec[i];
  }
  
  int sum=0;
  int resum=1;
  
  for(int j=1;j<n;j++){
    for(int k=0;k<j;k++){
      if(vec[k]<=vec[j]){
        sum+=1;
      }
    }
    if(sum==j){
      resum+=1;
      sum=0;
    }
    else{
      sum=0;
    }
    
  }
    cout<<resum<<endl;
      
  
}
