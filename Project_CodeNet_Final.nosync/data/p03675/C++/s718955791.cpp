#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <stack>

using namespace std;

int main(){
  long N,a;
  vector<long> b;
  cin >> N;
  for(int i=0;i<N;++i){
    cin >> a;
    b.push_back(a);
  }


  if(N%2==0){
      for(int i=N-1;i>=0;i -= 2){
        cout << b[i] << ' ';
      }
      for(int i=0;i<N-1;i += 2){
        cout << b[i] << ' ';
      }
  }else{
      for(int i=N-1;i>=0;i -= 2){
        cout << b[i] << ' ';
      }
      for(int i=1;i<N-1;i += 2){
        cout << b[i] << ' ';
      }
  }
  cout << endl;
}