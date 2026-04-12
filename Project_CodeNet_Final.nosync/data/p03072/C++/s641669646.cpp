#include <iostream>

using namespace std;

int main()
{
  int N;
  cin >> N;
  int H[N];
  for(int i = 0; i < N; i++) cin >> H[i];

  int count = 0;
  int maxH = H[0];
  for(int i = 0; i < N; i++){
    if(maxH <= H[i]) count++;
    maxH = max(maxH, H[i]);
  }

  cout << count << endl;

  return 0;
}
