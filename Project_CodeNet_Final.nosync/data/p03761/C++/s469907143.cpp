#include "bits/stdc++.h" 
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9

typedef long long unsigned int ll;

int n;
string s[50];

void solve(){
  vector<char> vs;
  rep(i, s[0].size()){
    bool can = true;
    rep(j, n-1){
      char a = s[0][i];
      int index = s[j+1].find(a);
      // cout << s[j+1] << " find " << a << endl;
      if(index != -1){
        //vs.push_back(a);
        s[j+1].erase(s[j+1].begin() +  index);
        // cout << "erase:" << s[j+1] <<endl;
      }else{
        can = false;
      }
    }
    if(can){
      vs.push_back(s[0][i]);
    }
  }
  sort(vs.begin(), vs.end());
  rep(i, vs.size()){
    cout << vs.at(i);
  }
  cout << endl;
}

int main(){
  cin >> n;
  rep(i, n){
    cin >> s[i];
  }
  solve();
}