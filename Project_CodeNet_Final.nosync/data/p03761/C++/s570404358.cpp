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
  ll n;
  cin >> n;
  ll ch[26];
  fill(ch,ch+26,400000);
  vector<string> s(n);
  for(int i=0;i<n;i++){
    cin >> s[i];
    ll tp[26];
    fill(tp,tp+26,0);
    for(char c:s[i]){
      tp[c-'a']++;
    }
    for(int i=0;i<26;i++){
      ch[i] = min(ch[i],tp[i]);
    }
  }
  for(int i=0;i<26;i++){
    for(int j=0;j<ch[i];j++){
      cout << (char)('a'+i);
    }
  }
  cout << endl;
}
