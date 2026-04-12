#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <deque>

int main(){
  int N;
  scanf("%d", &N);
  std::vector<int > A(N);
  for (int i=0; i<N; i++){
    scanf("%d", &A[i]);
  }
  std::sort(A.begin(), A.end(), std::greater<int>());
  long long ans = 0;
  if (N%2==1){
    long long temp=0;
    for (int i=0; i<N/2; i++){
      temp+=2*(long long)A[i];
    }
    for (int i=0; i<N/2-1; i++){
      temp-=2*(long long)A[N-1-i];
    }
    temp-=A[N/2];
    temp-=A[N/2+1];
    ans = std::max(ans, temp);
    temp = 0;
    for (int i=0; i<N/2-1; i++){
      temp+=2*(long long)A[i];
    }
    for (int i=0; i<N/2; i++){
      temp-=2*(long long)A[N-1-i];
    }
    temp+=A[N/2-1];
    temp+=A[N/2];
    ans = std::max(ans, temp);
  } else {
    long long temp = 0;
    for (int i=0; i<N/2-1; i++){
      temp += 2*(long long)A[i];
    }
    for (int i=0; i<N/2-1; i++){
      temp -= 2*(long long)A[N-1-i];
    }
    temp += A[N/2-1];
    temp -= A[N/2];
    ans = temp;
  }
  std::cout << ans << std::endl;
  return 0;
}
