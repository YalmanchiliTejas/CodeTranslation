#include <bits/stdc++.h>
using namespace std;

long long memo[100];
long long in[100];


long long search(int num, long long nokori){

  if(num == 0) return 1;

  long long ans = 0;
  nokori--;
  if(nokori == 0){
    return 0;
  }

  nokori -= memo[num-1];

  if(nokori < 0){
    return search(num-1, nokori+memo[num-1]);
  }

  if(nokori == 0){
    return in[num-1];
  }

  ans += in[num-1] + 1;
  nokori--;
  if(nokori == 0){
    return ans;
  }

  nokori -= memo[num-1];
  if(nokori < 0){
    return search(num-1, nokori+memo[num-1]) + ans;
  }

  return ans + in[num-1];
}

int main(){

  memo[0] = 1;
  in[0] = 1;

  for(int i = 1;i <= 50;i++){
    memo[i] = memo[i-1] * 2 + 3;
    in[i] = in[i-1] * 2 + 1;
  }

  long long n, x;
  cin >> n >> x;

  cout << search(n, x) << endl;

  return 0;
}