#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll mod=1e9+7;

int main(){
  int H,W;
  cin>>H>>W;
  string A[8];
  for (int i(0);i<H;i++)cin>>A[i];
  for (int h(0);h<H;h++){
    for (int w(0);w<W;w++){
      if (A[h][w]=='#'){
        for (int hi(h+1);hi<H;hi++){
          for (int wi(0);wi<=w-1;wi++){
            if (A[hi][wi]=='#'){
              cout << "Impossible" << endl;
              return 0;
            }
          }
        }
      }

    }
  }
  cout << "Possible" << endl;
  return 0;
}
