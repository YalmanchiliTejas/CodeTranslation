#include <iostream>

using namespace std;

int main(){
  int N,h,h_max=0,res=0;
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> h;
    if(h>=h_max) res++;
    h_max=max(h_max,h);
  }
  cout << res << endl;
  return 0;
}
