#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; 
  cin >> N;
  vector<int> A(N);
  int n=0;
for(int i=0;i<A.size();i++){
  cin >> A.at(i);
for(int j=0;j<=i;j++){
  if(A.at(i)<A.at(j)){
    break;
  }
  if(j==i){
  n++;
  }
  }
  }
  cout << n << endl;
}