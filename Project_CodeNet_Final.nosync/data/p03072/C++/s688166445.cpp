#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n; cin>>n;
  vector<int> h;
  int count=0;
  for(int i=0;i<n;i++){
    int x; cin>>x;
    h.push_back(x);
    sort(h.begin(),h.end());
    count++;
    if(x<h.at(i)){
      count--;
    }
  }
  cout<<count<<endl;
}