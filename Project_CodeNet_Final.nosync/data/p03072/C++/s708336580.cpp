#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
  int N, h[100]={0};
  int max=0, ans=0;
  cin >> N;
  for(int i=0; i < N; i++){
    cin >> h[i];
    if(h[i]>=max){
      ans++;
      max=h[i];
    }
  }
  cout << ans << endl;
  return 0;
}
