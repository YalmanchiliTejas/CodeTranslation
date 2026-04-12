#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
  int N;
  cin >> N;
  int count = 0,max=0;
  for(int i = 0; i < N; i++){
    int tmp;
    cin >> tmp;
    if(tmp >= max){
      max = tmp;
      count++;
    }
  }
  cout << count << endl;
}