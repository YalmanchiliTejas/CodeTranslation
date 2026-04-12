#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(int)n; i++)
using namespace std;
int main(){
  int n;
  
  int64_t c=0, d=0;
  cin >> n;
  int64_t a[n], k[n];
  rep(i, n){ 
    cin >> a[i];
    k[i]=a[i]%1000000007;
    d+=k[i];
  }  
  rep(i, n-1){
    d=d-k[i];
    int64_t e=d%1000000007;
    int64_t b=k[i]*e;
    c+=b;
    c=c%1000000007;
  }
  cout << c << endl;
}
      
      
