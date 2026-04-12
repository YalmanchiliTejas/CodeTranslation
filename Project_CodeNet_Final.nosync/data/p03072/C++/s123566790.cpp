#include<iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(){
  int N, count=0;
  cin >> N;
  int H[N+1];
  H[0]= 0;
  for(int i=0;i<N;i++){
    cin >> H[i+1];
  }

  for(int i=1;i<=N;i++){
    bool flag = true;
    for(int j=0;j<i;j++){
      if(H[j]>H[i]){
        flag = false;
        break;
      }
    }
    if(flag) count++;
  }

  cout << count <<endl;
  return 0;
}