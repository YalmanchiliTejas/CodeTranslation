#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> H(100);
  int count=1;
  int N;
  cin >> N;
  int k;
  
  for(int i=0; i < N; i++){
    cin >> H.at(i);
  }
  
  for(int i=1; i < N; i++){
    k=0;
    for(int j=0; j < i; j++){
      if(H.at(j) <= H.at(i))
        k++;
    }
    if(k==i)
      count++;
  }
  
  cout << count << endl;
}