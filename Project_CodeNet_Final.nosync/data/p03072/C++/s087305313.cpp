#include <iostream>
using namespace std;
int main(){
  int N,i,cnt=0,Hmax=-1,h;
  cin >> N;
  for(i=0;i<N;i++){
    cin >> h;
    if(h>=Hmax)cnt++;
    Hmax =max(h,Hmax);
  }
  cout << cnt << endl;
  return 0;
}