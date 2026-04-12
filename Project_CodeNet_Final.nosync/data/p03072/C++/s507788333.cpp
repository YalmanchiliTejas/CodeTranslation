#include <iostream>
#include <string>
typedef long long ll;
//#include <algorithm>
using namespace std;

int main() {
  int N;
  cin >> N;

  int h[1000];
  for(int i = 0; i < N; i++){
    cin >> h[i];
  }

  int max = 0;
  int num = 0;
  for(int i = 0; i < N; i++){
    if(max <= h[i]){
      max = h[i];
      num++;
    }
  }
  cout << num << endl;

}
