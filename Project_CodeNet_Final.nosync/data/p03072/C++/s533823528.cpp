#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int h[100];
  int max;
  cin >> max;
  int ct = 1;
  for(int i=1;i<n;i++){
    cin >> h[i];
    if(h[i]>=max){
      ct++;
      max = h[i];
    }
  }
  cout << ct << endl;


}
