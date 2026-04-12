#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin>>n;
  
  int h;
  int max=0,cnt=0;
  rep(i,n){
    cin>>h;
    if(h>=max) cnt++;
    if(h>max) max=h;
  }
  
  cout<<cnt<<endl;
  
  return 0;
}