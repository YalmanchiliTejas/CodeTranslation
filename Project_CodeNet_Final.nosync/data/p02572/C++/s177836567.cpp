#include <bits/stdc++.h>
using namespace std;
//NOT TO SUBMIT IN WRONG PLACE OR BY WRONG COMPILER
//ABC 177, task a, 2020/08/29
//ms,
/*
*/
#define P 1000000007

int main(void){
  int N;
  vector<int64_t> a;
  vector<int64_t> b;
  int64_t tmp_b=0;
  int64_t ans=0;


  cin >>N;
  for(int i=0;i<N;i++){
    int64_t tmp;
    cin >>tmp;
    a.push_back(tmp);
  }


  for(int i=N-2;i>=0;i--){
    tmp_b += a[i+1];
    tmp_b %= P;
    b.push_back(tmp_b);
  }

  for(int i=0;i<N-1;i++){
    ans += a[i]*b[N-2-i];
    ans %= P;
  }

  cout <<ans;

  return 0;
}
/*
*/
