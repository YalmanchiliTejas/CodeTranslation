#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n,ans;
  cin >> n;
  vector<int>a(n);
  for(int i;i<n;i++){
    cin >> a.at(i);
  }
  int p=a.at(0);
  ans=0;
  for(int i;i<n;i++){
    if(p<=a.at(i)){
      ans+=1;
      p=a.at(i);
    }
  }
  cout << ans << endl;
}