#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


int main()
{
  int N;
  cin >> N;

  vector<int> H(N);
  for(int i = 0; i < N; i++){
    cin >> H[i];
  }

  int maxH = H[0];
  int cnt = 1;
  for(int i = 1; i < N; i++){
    if(H[i] >= maxH){
      cnt++;
      maxH = H[i];
    }
  }

  cout << cnt << endl;

  return 0;
}
