#include <bits/stdc++.h>
using namespace std;

int Narry[10001] = {0};

int main(){
  int N,A,B,C,X;

  while(cin >>N>>A>>B>>C>>X){
    if(N == 0 and A == 0 and B == 0 and C == 0 and X == 0)break;
    int ans = -1,ind = 0;
    for(int i = 0; i < N ; i++){
      cin >>Narry[i];
    }

    int randnum = X;
    while(ind <= N-1){
      ans++;
      if(randnum == Narry[ind])ind++;
      if(ans > 10000){
        ans = -1;
        break;
      }
      randnum = (A*randnum + B)%C;
    }
    cout <<ans<<endl;
  }

  return 0;
}

