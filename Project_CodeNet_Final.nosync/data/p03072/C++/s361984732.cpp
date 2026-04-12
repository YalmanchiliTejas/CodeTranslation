#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int N;
  cin >> N;
  int H[N];
  for(int i = 0; i < N; i++){
    cin >> H[i];
  }
  int maxH = 0;
  int res = 1;
  for(int i = 0; i < N-1; i++){
    maxH = max(maxH, H[i]);
    if(H[i+1] >= H[i] && H[i+1] >= maxH){
      res++;
    }
  }
  cout << res << endl;
}