#include<bits/stdc++.h>

using namespace std;
using ll=long long;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, a, n) for(int i = (n); i < (a); i++)

int main(){
  cin.tie(nullptr);ios_base::sync_with_stdio(false);
  int n;cin>>n;
  int cnt=1,h,hoge;
  cin>>h;
  hoge=h;
  rep(i,n-1){
    cin>>h;
    if(h>=hoge){
      hoge=h;
      cnt++;
    }
  }
  cout<<cnt<<endl;
}
