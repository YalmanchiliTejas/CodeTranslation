#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long> t,p;
long getans(int n, long x){
  if(x == 1){
    if(n == 0) return 1;
    else return 0;
  }else if(x <= 1 + t[n - 1]){
    return getans(n - 1, x - 1);
  }else if(x == 2 + t[n - 1]){
    return p[n - 1] + 1;
  }else if(x < 3 + 2 * t[n - 1]){
    return p[n - 1] + 1 + getans(n - 1, x - (2 + t[n - 1]));
  }else{
    return p[n - 1] * 2 + 1;
  }
}
  
int main(){
  long N, X;  
  cin >> N >> X;

  t.push_back(1);
  p.push_back(1);
  for(int i = 1; i < N; ++i){
    t.push_back(t[i - 1] * 2 + 3);
    p.push_back(p[i - 1] * 2 + 1);
  }
  
  cout << getans(N, X) << endl;
  
  return 0;
}