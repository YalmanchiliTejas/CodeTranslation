#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll mod=1e9+7;

int main(){
  int n;
  ll a[200000];
  cin>>n;
  for (int i(0);i<n;i++) cin>>a[i];
  if (n%2==0){
    int x(n-1);
    while (x>=1){
      cout << a[x]<<" ";
      x-=2;
    }
    x=0;
    while (x<=n-1){
      cout << a[x]<<" ";
      x+=2;
    }
  }else{
    int x(n-1);
    while (x>=0){
      cout << a[x]<<" ";
      x-=2;
    }
    x=1;
    while (x<=n-1){
      cout << a[x]<<" ";
      x+=2;
    }
  }
  cout << endl;
}
