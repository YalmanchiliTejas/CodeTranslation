#include <bits/stdc++.h>
using namespace std;

int main(){
int N;
cin>>N;
  vector<int> vec(N);
  int sum=0;
  int max=0;
  for(int i=0;i<N;i++){
    cin>>vec.at(i);  
    
    if(max<=vec.at(i)){
      max=vec.at(i);
      sum++;
    }
    
    
  }
  
    cout<<sum<<endl;
  }
  
