#include<iostream>
#include<string>

using namespace std;

int main() {
  int sum = 0;
  int N;

  cin >> N;

  for(int i=1;i<=N;i++){
      sum += 800;
      if(i%15==0){
        sum -= 200;
      }
  }
  std::cout << sum << endl;
  return 0;
}
