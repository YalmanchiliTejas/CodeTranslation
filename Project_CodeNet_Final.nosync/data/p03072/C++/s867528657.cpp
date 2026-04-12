#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
  int n,ans=0;
  cin >>n;
  vector<int> h(n,0);
  rep(i,n){
    cin >>h[i];
  }
  rep(i,n){
    bool f=true;
    for(int j=0;j<i;j++){
      if(h[j]>h[i]) f=false;
    }
    if(f==true) ans++;
  }
  cout << ans <<endl;
}

