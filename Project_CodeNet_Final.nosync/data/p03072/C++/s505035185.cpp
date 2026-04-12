#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  int H[N];
  int j = 0;
  int mx = 0;
  for(int i = 0; i < N; i++){
    cin >> H[i];
    if(H[i] >= mx){
      j++;
      mx = H[i];
    }
  }
  printf("%d\n\r", j);
}

    