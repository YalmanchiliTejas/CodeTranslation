#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int H[N];
  for(int i=0;i<N;i++){
    cin >> H[i];
  }
  int count=0;
  for(int i=1;i<N;i++){
    bool X=true;
    for(int j=0;j<i;j++){
      if(H[j]>H[i]){
        X=false;
      }
    }
    if(X){
      count++;
    }
  }
  cout << count+1;
}