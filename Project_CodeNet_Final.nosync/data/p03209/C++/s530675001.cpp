#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[51],p[51];
ll bg(int l,long long x){
  if(l == 0){
    if(x<=0){
      return 0;
    }
    else{
      return 1;
    }
  }
  if(x == 1){
    return 0;
  }
  else if(1<x && x <= 1+s[l-1]){
    return bg(l-1,x-1);
  }
  else if(x == s[l-1] + 2){
    return 1+p[l-1];
  }
  else if(3+s[l-1] <= x && x <= 2+2*s[l-1]){
    return p[l-1] + 1 + bg(l-1,x-(2+s[l-1]));
  }
  else if(x == 3+2*s[l-1]){
    return 2*p[l-1]+1;
  }
}
int main(){
  int n;
  ll x;
  cin >> n >> x;
  
  s[0] = 1;
  p[0] = 1;
  for(int i=0; i<n; i++){
    if(i>0){
      s[i] = 2*s[i-1] + 3;
      p[i] = 2*p[i-1] + 1;
    }
  }
  
  cout << bg(n,x) << endl;
}