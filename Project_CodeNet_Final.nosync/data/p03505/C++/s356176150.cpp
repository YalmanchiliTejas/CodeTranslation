#include<bits/stdc++.h>
using namespace std;
int main(){
  long long k,a,b,ans;cin >> k >> a >> b;
  if(k>a && a<=b){
    cout << -1 << "\n";return 0;
  }
  if(a<=b){
    cout << 1 << "\n";return 0;
  }
  cout << (k-b-1)/(a-b)*2+1 << "\n";
}
  