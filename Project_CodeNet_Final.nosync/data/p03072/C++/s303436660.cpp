#include <iostream>
using namespace std;
int main(void){
  int N;
  cin >> N;
  int H[N];
  int res=0;
  for(int i=0; i<N; ++i){
    cin >> H[i];
    if(i==0){
      ++res;
      continue;
    }
    for(int j=0; j<i; ++j){
      if((H[j]>H[i])&&(i!=0)){
        break;
      }
      else if((j==(i-1))||(i==0)){
        ++res;
      }
    }
  }
  cout<<res;
}