#include <algorithm>
#include<iostream>
using namespace std;
int main(){
  int n;
  cin >> n;

  int h[110];
  for(int i = 0; i < n; i++) cin >> h[i];

  int max_h = 0;
  int count = 0;

  for(int i = 0; i < n; ++i){
    if(max_h <= h[i]){
      max_h = h[i];
      count++;
    }
  }
  cout << count << endl;
}
