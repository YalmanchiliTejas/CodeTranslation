#include<iostream>
#include<vector>

using namespace std;

int main(){
  int n,i,j,mx=0,c=0;
  cin>>n;
  vector<int> h(n);
  for(i=0;i<n;i++) cin>>h.at(i);
  for(i=0;i<n;i++){
    if(h[i]>=mx){
      c++;
      mx=h[i];
    }

  }
  cout<<c<<endl;

}
