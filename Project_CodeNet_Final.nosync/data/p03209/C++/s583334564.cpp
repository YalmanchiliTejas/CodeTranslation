#include<bits/stdc++.h>

using namespace std;

long long burger(long long n, long long x){
  if(n == 0ll) return 1ll;
  else if(x == 1ll) return 0ll;
  else if(x <= (1ll << (n + 1ll)) - 2ll){
    return burger(n - 1ll, x - 1ll);
  }else if(x <= (1ll << (n + 1ll)) - 1ll){
    return 1ll << n;
  }else if(x <= (1ll << (n + 2ll)) - 4ll){
    return burger(n - 1ll, x - (1ll << (n + 1ll)) + 1ll) + (1ll << n);
  }else{
    return (1ll << (n + 1ll)) - 1ll;
  }
}

int main(){
  long long n, x;
  cin >> n >> x;
  
  cout << burger(n, x) << endl;
  
  return 0;
}
