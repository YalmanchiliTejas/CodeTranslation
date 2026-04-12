#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
using namespace std;


int main(){
  long long n, x;
  cin >> n >> x;
  long long length[n + 1], sum_p[n + 1];
  sum_p[0] = 1;
  length[0] = 1;
  for (int i = 1; i <= n; i++){
    sum_p[i] = sum_p[i - 1] * 2 + 1;
    length[i] = length[i - 1] * 2 + 3;
  }
  long long answer = 0;
  for (int i = n - 1; i >= 0; i--){
    if (x >= length[i] * 2 + 2){
      answer += sum_p[i] * 2 + 1;
      break;
    }
    else if (x > length[i] + 2){
      answer += sum_p[i] + 1;
      x -= length[i] + 2;
    }
    else if (x == length[i] + 2){
      answer += sum_p[i] + 1;
      break;
    }
    else if (x == length[i] + 1){
      answer += sum_p[i];
      break;
    }
    else if (x > 1){
      x -= 1;
    }
  }
  cout << answer << endl;
  return 0;
}
