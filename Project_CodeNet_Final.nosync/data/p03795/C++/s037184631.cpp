#include<iostream>
#include<math.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  int payback=0;
  payback=200*floor(N/15);
  cout<<800*N-payback<<endl;
  return 0;
}
