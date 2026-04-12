#include<iostream>
using namespace std;
int main(){
  int N, count, max, height;
  cin >> N;
  count =0;
  max =0;
  for(int i=0; i<N; i++){
    cin >> height;
    if(max <= height){
      max = height;
      count++;
    }
  }
  cout << count << endl;
  return 0;
}