#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

int main(){

  int N, M;
  scanf("%d", &N);
  scanf("%d", &M);

  std::vector<std::vector<int > > to(N+5);
  int temp1, temp2;
  long long ans = 0;
  for (int i=0; i<M; i++){
    scanf("%d",&temp1);
    scanf("%d",&temp2);
    temp1--; temp2--;
    to[temp1].push_back(temp2);
    to[temp2].push_back(temp1);
  }
  int array[N];
  for (int i=0; i<N; i++){
    array[i] = i;
  }
  do {
    /*for (int i = 0; i < N; i++) {
      std::cout << array[i] << " ";
    }
    std::cout<< " "<<std::endl;*/
    if (array[0]!=0){
      break;
    } else {
      bool ansbool = true;
      for (int index = 0; index<N-1; index++){
        int number = array[index];
        bool okflag = false;
        for (int i=0; i<to[number].size(); i++){
          if (to[number][i]==array[index+1]){
            okflag = true;
            break;
          }
        }
        if (!okflag){
          ansbool = false;
        }
      }
      //printf("result=%d\n",ansbool);
      if (ansbool){
        ans++;
      }
    }
  } while (std::next_permutation(array, array+N));
  printf("%lld\n", ans);
  return 0;
}
