#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define _GLIBCXX_DEBUG
static const int MAX = 20;

int main(){
  int N;
  cin >> N;
  int H[MAX];
  int count = 1;
  int Hmax;
  rep(i, N) cin >> H[i];
  Hmax = H[0];
  rep2(i, 1, N){
    if(Hmax <= H[i]) count++;
    Hmax = max(H[i], Hmax);
  }

  cout << count << endl;
}