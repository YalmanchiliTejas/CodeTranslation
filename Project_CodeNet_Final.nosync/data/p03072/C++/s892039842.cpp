#include <iostream>
#include <vector>

using namespace std;


int main(){

  int N;
  cin >> N;
  std::vector<int> vH(N);

  int h;
  for(int i = 0; i< N; ++i){
    cin >> h;
    vH.at(i) = h;
  }

  int ans = 0;
  int hMax = 0;
  for(int i = 0; i < N; ++i){
    if(vH.at(i) >= hMax){
      ans += 1;
      hMax = vH.at(i);
    }
  }

  std::cout << ans << std::endl;

  return 0;

}
