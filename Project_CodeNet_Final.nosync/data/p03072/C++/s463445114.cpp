#include <bits/stdc++.h>
using namespace std;
 
int main(){
int N;
  cin >> N;
int h[N];
  for(int i = 0; i < N;i++) cin >> h[i];
  
  int now = 0;
  int sum = 0;
  
  for(int i = 0; i < N;i++) {
  if(now <= h[i]){
  now = h[i];
    sum++;
  }  
  }
  
  cout << sum << endl;
  
 
return 0;
  
}