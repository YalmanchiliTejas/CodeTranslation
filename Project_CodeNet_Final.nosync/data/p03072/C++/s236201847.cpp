#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int sum=0;
  int H=0;
  int M;
  for(int i=0;i<N;i++){
    cin >> M;
    if(M>=H){
      H=M;
      sum++;
    }
    else{
    }
  }
  cout << sum <<endl;
}
