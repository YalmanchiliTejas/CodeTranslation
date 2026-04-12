#include <iostream>
using namespace std;
int main(){
  int N;
  int *H;
  cin>>N;
  H = new int[N];
  for(int i =0; i<N; i++)cin>>H[i];
  int view = 0;
  bool flag;
  for(int i =0; i<N; i++){
    flag=true;
    for(int j=0; j<i; j++){
      if(H[j]>H[i]){
        flag=false;
        break;
      }
    }
    if(flag) view+=1;
  }
  cout<<view;
  return 0;
}