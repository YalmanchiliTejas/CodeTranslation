#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  int H[30];
  int count;
  int max;
  cin >> N;
  for(int i=0; i < N; i++){
    cin >> H[i];
  }
  max = H[0];
  count = 1;
  for(int i=1; i < N; i++){
    if (H[i]>=max){
      max = H[i];
      count++;
    }
  }
  cout << count << endl;
}