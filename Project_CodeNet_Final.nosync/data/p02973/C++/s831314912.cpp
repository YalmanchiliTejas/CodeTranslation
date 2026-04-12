#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  vector<int> arr;
  for(int i=0;i<n;++i){
    int tmp;cin>>tmp;
    bool f = true;
    
    if(arr.size()==0 || tmp <= arr[arr.size()-1]){
      arr.push_back(tmp);
      continue;
    }
    
    for(int j=0;j<arr.size();++j){
      if(tmp > arr[j]){
        arr[j] = tmp;
        break;
      } 
    }
    
  }
  cout<<arr.size()<<endl;
  return 0;
}
