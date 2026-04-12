#include <iostream>
#include <vector>

using namespace std;

int main(void){
  int N;
  cin >> N;
  vector<int> H;
  H.resize(N);
  for (int i = 0; i < N;i++){
    cin >> H[i];
  }

  int count = 1;

  for (int i = 1; i < N; i++){
    bool flag = true;

    for (int j = 0; j < i; j++){
      if(H[j]>H[i]){
        flag = false;
        continue;
      }
    }
    if(flag==true){
      count++;
    }
  }

  cout << count << endl;
}
