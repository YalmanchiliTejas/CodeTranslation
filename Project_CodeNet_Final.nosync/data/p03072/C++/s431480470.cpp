#include <bits/stdc++.h>
using namespace std;
int main() {
  int N = 0;
  cin >> N;
  vector<int> vec(N);
  int h = 0;
  int x = 0;
   for (int i = 0; i < N; i++) {
     cin>> vec.at(i);
     h = vec.at(0);
   }
   for (int i = 0; i < N; i++) {
     if (vec.at(i) >= h){
       h = vec.at(i);
       x ++;
     }
   }
    cout << x << endl;
}