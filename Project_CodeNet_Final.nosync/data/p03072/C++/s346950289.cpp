#include<iostream>
using namespace std;
int main(){
  int n, h, i=0, height=0, ans=0;
  cin >> n;
  for(;i<n;i++){
    cin >> h;
    if(h>=height){
      ans++;
      height=h;
      }
    }
  cout << ans << endl;
  }