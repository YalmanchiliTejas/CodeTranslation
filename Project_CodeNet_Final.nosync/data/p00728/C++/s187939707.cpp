#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n,num[1000];
  while(1){
  cin >> n;
  if(!n)break; 
  for(int i = 0 ; i < n ; i++){
    cin >> num[i];
  }
  sort(num,num+n);
  int ans = 0;
  for(int i = 1 ; i < n-1 ; i++){
    ans += num[i];
  }
  cout << ans/(n-2) << endl;
  }
  return 0;
}