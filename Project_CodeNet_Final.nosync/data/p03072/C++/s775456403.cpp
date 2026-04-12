#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N;
  cin >> N;

  vector<int> H(N);

  for (int i = 0; i < N; i++)
  {
    cin >> H.at(i);
  }

  int cnt = 0;
  bool flg;
  for (int i = 0; i < N; i++)
  {
    if (i == 0){
      cnt += 1;
      continue;
    }
    flg = true;
    for (int j = 0; j < i; j++)
    {
      if (H.at(j) > H.at(i)) flg = false;
    }
    if (flg) cnt += 1;
  }
  
  cout << cnt << endl;
}