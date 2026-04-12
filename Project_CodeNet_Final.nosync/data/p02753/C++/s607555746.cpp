// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(10);
}
signed main(){
  init_io();
  string s;
  cin >> s;
  for(int i=1;i<3;i++){
    if(s[i-1]!=s[i]){
      cout <<"Yes\n";
      return 0;
    }
  }
  cout <<"No\n";
}
