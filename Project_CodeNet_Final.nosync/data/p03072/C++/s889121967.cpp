#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  
  cin >> N;
  
  int H[N],A[N];
  
  int top=0;
  
  int count=0;
  
  for (int i=0;i < N;i++){
    cin >> H[i];
    if (top <= H[i]){
      top=H[i];
      count++;
    }
  }
  cout << count;
}