#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <cstring>
#include <algorithm>

int init_BIT(std::vector<long long int> &BIT, int N_MAX);
int add_num(std::vector<long long int> &BIT, long long int N_MAX, long long int index, long long int d);
long long int cumulative_sum(std::vector<long long int> &BIT, long long int r);

int compress_vector(std::vector<long long int> &vec, long long int N, long long int start);


int main(){
  
  // read problem
  long long int N, tmp;
  std::vector<long long int> A;
  scanf("%lld", &N);
  for(long long int i = 0; i < N; i++){
    scanf("%lld", &tmp);
    A.push_back(tmp-1);
  }
  
  compress_vector(A, N, 0);
  
  /*std::cerr << "A:" << std::endl;
  for(long long int i = 0; i < N; i++){
    std::cerr << A[i] << " ";
  }std::cerr << std::endl;*/
  
  // prepare BIT
  long long int N_MAX = 1<<17;
  std::vector<long long int> BIT;
  for(int i = 0; i < N_MAX; i++){
    BIT.push_back(0);
  }
  
  // solve problem
  long long int l, r, mid, sum_tmp;
  
  for(long long int i = 0; i < N; i++){
    // if already existing color is used
    sum_tmp = cumulative_sum(BIT, A[i]-1);
    if(sum_tmp > 0){
      //std::cerr << "i = " << i << ": new color is not used:" << std::endl;
      if(cumulative_sum(BIT, 0) == sum_tmp) r = 0;
      else{
        l = 0;
        r = A[i]-1;
        while(r-l>1){
          mid = (l+r)/2;
          if(cumulative_sum(BIT, mid) == sum_tmp) r = mid;
          else l = mid;
        }
      }
      add_num(BIT, N_MAX, r, -1);
      add_num(BIT, N_MAX, A[i], 1);
    }
    
    // if new color is used
    else{
      //std::cerr << "i = " << i << ": new color is used:" << std::endl;
      add_num(BIT, N_MAX, A[i], 1);
    }
    
    // print current state
    /*std::cerr << "current cumulative sum:" << std::endl;
    for(long long int i = 0; i < N; i++){
      std::cerr << cumulative_sum(BIT, i) << " ";
    }std::cerr << std::endl;*/
  }
  
  std::cerr << "Answer:" << std::endl;
  std::cout << cumulative_sum(BIT, N-1) << std::endl;
  
  /*
  long long int N_MAX = 1<<20; // aproximately

   std::vector<long long int> BIT;
   for(int i = 0; i < N_MAX; i++){
     BIT.push_back(0);
   */

  return 0;
}


int add_num(std::vector<long long int> &BIT, long long int N_MAX, long long int index, long long int d){
  index ++;
  while(index < N_MAX){
    BIT[index-1] += d;
    index += (index & -index);
  }
  
  return 0;
}

long long int cumulative_sum(std::vector<long long int> &BIT, long long int r){
  // sum of no elements
  if(r == -1){
    return 0;
  }
  
  r++;
  long long int sum = 0;
  while(r > 0){
    sum += BIT[r-1];
    r -= (r & -r);
  }
  
  return sum;
}

int compress_vector(std::vector<long long int> &vec, long long int N, long long int start){
  
  // make pair of index and entry of given vector
  std::vector< std::pair<long long int, long long int> > vec_pair;
  for(long long int i = 0; i < N; i++){
    vec_pair.push_back(std::make_pair(vec[i], i));
  }
  // sort vector
  std::sort(vec_pair.begin(), vec_pair.end());
  
  // compress
  long long int tmp1 = vec_pair[0].first, tmp2 = start;
  vec_pair[0].first = tmp2;
  for(long long int i = 1; i < N; i++){
    if(vec_pair[i].first != tmp1){
      tmp2++;
      tmp1 = vec_pair[i].first;
    }
    vec_pair[i].first = tmp2;
  }
  
  // re-sort in terms of index
  for(long long int i = 0; i < N; i++){
    tmp1 = vec_pair[i].first;
    vec_pair[i].first = vec_pair[i].second;
    vec_pair[i].second = tmp1;
  }
  std::sort(vec_pair.begin(), vec_pair.end());
  
  // write answer to vec
  for(long long int i = 0; i < N; i++){
    vec[i] = vec_pair[i].second;
  }

  return 0;
}
