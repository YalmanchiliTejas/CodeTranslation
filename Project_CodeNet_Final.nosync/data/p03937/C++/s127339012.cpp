#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

int main(){
  int H,W; cin>>H>>W;
  int cnt=0;
  rep(i,H) rep(j,W){
    char x; cin>>x;
    if(x=='#') cnt++;
  }
  if(cnt==(H+W-1)) cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;
  return 0;
}
