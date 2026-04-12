#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll d[55];
ll f(int n, ll x){
  if(n >= x) return 0;
  if(n == 0) return 1;
  ll maxnum = ((ll)4<<n)-3;
  //cout << "n=" << n << " x:" << x << " maxnum:"<< maxnum << endl;
  if(x >= maxnum -1){
    if(d[n] != 0) return d[n];
    else return d[n] = f(n-1, maxnum/2-1) *2 +1;
  }
  else if(x >= maxnum/2+1){
    return f(n-1, x -maxnum/2-1) +1 +f(n-1, maxnum/2-1);
  }
  else{
    return f(n-1, x-1);
  }
}

int main(){
  int n;
  ll x;
  cin >> n >> x;
  cout << f(n,x) << endl;
}