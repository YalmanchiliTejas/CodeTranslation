#include<iostream>
#include<vector>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> h(n);
  for(int i=0; i<n; i++)
    cin>>h[i];

  int sum=1;
  int max=h[0];

  for(int i=1; i<h.size(); i++){
    if(max<=h[i]){
      sum++;
      max=h[i];
    }
  }
  cout<<sum<<endl;
  return 0;
}
