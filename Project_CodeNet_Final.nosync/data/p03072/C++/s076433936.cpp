#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include <climits>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> H(N);

  for(int i=0; i<N; i++){
    cin >> H[i];
  }

  int count = 1;
  int look = 1;
  for(int i=1; i<N; i++){
    int look = 1;
    for(int j=0; j<i; j++){
      if(H[j] > H[i]){
        look = 0;
      }
    }
    if(look == 1){
      count++;
    }
  }
  cout << count << endl;
  return 0;
}
