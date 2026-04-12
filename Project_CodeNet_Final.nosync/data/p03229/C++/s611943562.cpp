#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t N;
  cin >> N;
  vector<int64_t> vec(N);
  for(int i=0; i<N; i++){
    cin >> vec.at(i);
  }
  sort(vec.begin(),vec.end());
  
  int64_t sum_a = 0;
  int64_t a = 0;
  int64_t b = N-2;
  for(int i=0; i<(N+1)/2-1; i++){
    sum_a += abs(vec.at(a) - vec.at(b));
    if(i%2 == 0){
      a += 2;
    }
    else{
      b -= 2;
    }
  }
  a = N-1;
  b = 1;
  for(int i=0; i<N/2-1; i++){
    sum_a += abs(vec.at(a) - vec.at(b));
    if(i %2 == 0){
      a -= 2;
    }
    else{
      b += 2;
    }
  }
  sum_a += (vec.at(N-1) - vec.at(0));
  
  
  int64_t sum_b = 0;
  
  a = N-1;
  b = 0;
  for(int i=0; i<(N+1)/2-1; i++){
    sum_b += abs(vec.at(a) - vec.at(b));
    if(i%2 == 0){
      a -= 2;
    }
    else{
      b += 2;
    }
  }
  a = 1;
  b = N-2;
  for(int i=0; i<N/2-1; i++){
    sum_b += abs(vec.at(a) - vec.at(b));
    if(i %2 == 0){
      a += 2;
    }
    else{
      b -= 2;
    }
  }
  sum_b += vec.at(N-1) - vec.at(1);
  
  cout << max(sum_a,sum_b) << endl;
}