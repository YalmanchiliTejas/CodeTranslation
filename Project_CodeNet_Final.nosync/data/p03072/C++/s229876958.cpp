#include <iostream>
#include <string>
using namespace std;

int main(){
  int N;
  cin >> N;
  int H[N];
  for (int i=0; i < N; i++){
    cin >> H[i];
  }

  int out = 1;

  for (int i=1; i < N; i++){
    // i番目の山から海が見えるかどうか
    int visivle = 1;
    for (int j=0; j < i; j++){
      if (H[j] > H[i]){
        visivle = 0;
        break;
      }
    }
    if (visivle == 1){
      out += 1;
    }
  }

  cout << out << endl;
  return 0;
}
