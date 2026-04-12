#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int n;
  cin >> n;
  int ans=0;
  int m=0;
  rep(i,n){
    int a;
    cin >> a;
    if(a>=m){
      m=a;
      ans++;
    }
  }
  cout << ans << endl;
}
