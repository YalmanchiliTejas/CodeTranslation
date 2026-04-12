#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> vec(N);
  for(int i=0; i<N; i++){
    cin >> vec.at(i);
  }
  int height = 0;
  int count = 0;
  for(int j=0; j<N; j++){
    if(vec.at(j) >= height){
      height = vec.at(j);
      count++;
    }
  }
  cout << count << endl;
}