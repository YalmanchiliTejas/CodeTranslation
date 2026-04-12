#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
 
int main() {
  int n;
  cin>>n;
  int ans=0;
  int ma=0;
  vector<int>a(n);
  rep(i,n){
    cin>>a.at(i);
    if(a.at(i)>=ma){
      ans++;
      ma=a.at(i);
    }
  }
  cout<<ans<<endl;
}