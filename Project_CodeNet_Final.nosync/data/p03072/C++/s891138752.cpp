#include "bits/stdc++.h"
using namespace std;
 
int main() {
  int N,res=1,Hmax=0;

  cin >> N;
  vector<int> H(N);

  for (int i = 0; i < N; i++)
  {
    cin >> H.at(i);
  }

  Hmax = H.at(0);
  for(int i = 1; i < N; i++)
  {
     if(H.at(0) <= H.at(i)){
       if(Hmax <= H.at(i)){
        res++;
        Hmax = H.at(i);
       }
     }
     
  }
  cout << res << endl;

}