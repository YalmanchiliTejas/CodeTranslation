#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using vvl = vector<vector<long>>;
using pii = pair<int, int>;
using pil = pair<int, long>;
using pll = pair<long, long>;
#define fix20 cout << fixed << setprecision(20)
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define REP(i,s,t) for(int i=s; i<t; i++)
#define RNG(i,s,t,u) for(int i=s; i<t; i+=u)
#define MOD 1000000007
#define all(vec) vec.begin(), vec.end()


bool check(vb &animal, string s){
  int n = s.size();
  REP(i,1,n-1){
    if(animal.at(i)){
      if(s.at(i) == 'o') animal.at(i+1) = animal.at(i-1);
      else animal.at(i+1) = (!animal.at(i-1));
    }else{
      if(s.at(i) == 'o') animal.at(i+1) = (!animal.at(i-1));
      else animal.at(i+1) = animal.at(i-1);
    }
    //cout << animal.at(i) << " " << s.at(i) << " " << animal.at(i-1) << " " << animal.at(i+1) << endl;
  }
  bool flag;
  if(animal.at(n-1)){
    if(s.at(n-1) == 'o') flag = animal.at(0) == animal.at(n-2);
    else flag = animal.at(0) != animal.at(n-2);
  }else{
    if(s.at(n-1) == 'o') flag = animal.at(0) != animal.at(n-2);
    else flag = animal.at(0) == animal.at(n-2);
  }
  if(!flag) return false;
  if(animal.at(0)){
    if(s.at(0) == 'o') return animal.at(n-1) == animal.at(1);
    else return animal.at(n-1) != animal.at(1);
  }else{
    if(s.at(0) == 'o') return animal.at(n-1) != animal.at(1);
    else return animal.at(n-1) == animal.at(1);
  }
}

int main(){
  int n;
  string s;
  cin >> n >> s;
  rep(i,2){
    rep(j,2){
      vector<bool> animal(n);
      animal.at(0) = i;
      animal.at(1) = j;
      if(check(animal,s)){
        rep(i,n){
          if(animal.at(i)) cout << "S";
          else cout << "W";
        }
        cout << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
}
