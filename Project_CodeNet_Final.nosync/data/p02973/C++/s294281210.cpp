#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>

using namespace std;

const int nmax = 1e9 + 7;
const long long INF = 1e18;
const double PI = 2 * asin(1);
typedef long long ll;

int main(){

  int N; cin >> N;
  vector <int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  vector <int> ans;
  ans.push_back(A[N - 1]);


  for (int i = N - 2; i >= 0; i--){
    int T = A[i];

    if (ans[ans.size() - 1] <= T){
      ans.push_back(T);
    }else{
      int L = 0, R = ans.size() - 1;

      bool flag = true;      

      while (flag == true){
        int now = (L + R) / 2;

        if (T < ans[now]) R = now;
        else L = now;

        if (now == (L + R) / 2){
          if (T < ans[L]) ans[L] = T;
          else ans[R] = T;

          break;
        }
      }
    }

  }

  cout << ans.size() << endl;
  return 0;
}
