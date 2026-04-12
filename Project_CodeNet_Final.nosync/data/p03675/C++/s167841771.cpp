#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a;
  for(int i=0;i<n;i++){
    int num;cin>>num;
    a.push_back(num);
    }
  if(n%2==0){
    for(int i=a.size()-1;i>=0;i-=2){
      cout<<a[i]<<" ";
    }
    for(int i=0;i<a.size()-1;i+=2){
      cout<<a[i]<<" ";
    }
    cout<<endl;
  }else{
    for(int i=a.size()-1;i>=0;i-=2){
      cout<<a[i]<<" ";
    }
    for(int i=1;i<a.size()-1;i+=2){
      cout<<a[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}