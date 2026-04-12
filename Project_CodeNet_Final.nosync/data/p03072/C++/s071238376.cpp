#include <iostream>
using namespace std;

int main() {
  int N;
  cin>>N;
  int ans = 0;
  int h;
  int maxh = 0;
  
  for(int i = 0;i < N;i++){
    cin>>h;

    if(h >= maxh){
      maxh = h;
      ans++;
    }
  }

  cout<<ans;
  return 0;
}