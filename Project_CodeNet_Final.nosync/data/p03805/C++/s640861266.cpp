#include <stdio.h>		// standard input output
#include <iostream>		// input output stream, cin cout( console in console out)
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>		// input output manipulation

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long 

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> a(M),b(M),v(N-1);
  rep(i,M){
    cin >> a.at(i) >> b.at(i);
  }
  rep(i,N-1){
    v.push_back(i+2); //2,...,N
  }
  
  bool flg;
  int left, right, cnt=0;
  while(1){
    for(int i=0; i<N-1; i++){
      flg = false;
      if(i==0) left = 1;
      else left = v.at(i-1);
      right = v.at(i);
      
      for(int j=0; j<M; j++){
        if((left == a.at(j) && right == b.at(j))
           || (left == b.at(j) && right == a.at(j))){
          //cout << "left, right: " << left << right << "   a, b: " << a.at(j) << b.at(j) << endl;
          flg = true;
          break;
        }
      }
      if(!flg) break;
    }
    if(flg) cnt++;
    if(!next_permutation(v.begin(), v.end())) break;
  }
    
  cout << cnt << endl; // 標準出力
}