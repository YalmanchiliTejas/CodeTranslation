#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int ans;
  int x=0;
  vector<int> vec(N);
  
  for(int i=0;i<N;i++){
  cin >> vec.at(i);
  }
  for(int i=0;i<N;i++){
   if(x<= vec.at(i)){
     x=vec.at(i);
     ans++;
     
    }
  }
  
  
  cout << ans << endl;
}