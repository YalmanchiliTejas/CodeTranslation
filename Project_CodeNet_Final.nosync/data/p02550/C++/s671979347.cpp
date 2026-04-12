//設定言語check
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <limits.h>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
using namespace std;

int main(){
  long long int N, ans = 0, X, M, kind = 1, count = 1, type = 0 ;
  cin >> N >> X >> M ;
  long long int exists[M+5] = {}, A[M+5] = {} ;
  A[1] = X ;
  exists[X] = 1 ;
  while(type == 0 ){
    count++ ;
    A[count] = (A[count-1] * A[count-1]) % M ;
    if(exists[A[count]] == 1){
      type = 1 ;
    }
    else if(count == N){
      type = 2 ;
    }
    else{
      exists[A[count]] = 1 ;
      kind++ ;
    }
  }
  if(type == 2){
    for(int i=1;i<N+1;i++){
      ans += A[i] ;
    }
  }
  else{
    int loops = 0 ;
    while(( A[count] != A[count - loops]) || (loops == 0) ){
      ans += A[count - loops] ;
      loops++ ;
    }

    int unloop = count - loops - 1 ;
    long long int many = (N-unloop) / loops ;
    ans = ans * many ;
    int left = ( (N-unloop) % loops) + unloop ;
    for(int i=1;i<left+1;i++){
      ans += A[i] ;
    }
  }
  cout << ans << endl ;
  return 0 ;
}