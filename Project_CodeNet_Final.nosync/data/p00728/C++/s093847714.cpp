#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main(void){

while(true){
  int n, input; cin >> n;
  if(n == 0)     break;
  
  int max_point = 0, min_point = 1000, sum = 0;
  for(int i = 0 ; i < n ; i++){
    cin >> input;
    min_point = min(min_point , input);
    max_point = max(max_point , input);
    sum += input;
  }
  sum -= min_point + max_point;

  cout << sum / (n - 2) << endl;

}

  return 0;
}
