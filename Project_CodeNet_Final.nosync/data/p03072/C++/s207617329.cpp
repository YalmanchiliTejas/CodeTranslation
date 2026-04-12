#include <iostream>
using namespace std;
int main(){
  int N,l;
  int i = 0;
  int a[100];
  cin >> N;
  
  int currentmax = 0;
  int ct = 0;
  
  while(cin>>l){
    a[i] = l;
    if (currentmax <= l){
      ct+=1;
      currentmax = l;
    }
    i++;
  }
  printf("%d",ct);
  return 0;
  
}