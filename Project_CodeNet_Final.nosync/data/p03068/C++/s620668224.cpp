#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  char c[N];
  int K;
  cin >> N;
  cin >> c;
  cin >> K;
    for(int i = 0;i<N;i++){
      if(c[K - 1] == c[i]){
        cout << c[K - 1];
      }
      else{
        cout << "*";
      }
    }
  cout << endl;
}
