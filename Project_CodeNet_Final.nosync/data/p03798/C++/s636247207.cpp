#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
template <typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template <typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int INT_INF = 1 << 30;
#define MOD 1000000007LL
#define endl "\n"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll N;
  cin >> N;
  string s;
  cin >> s;

  auto func = [&](string ss){
    char c = ss.at(0), cc = ss.at(N-1);
    for(int i = 1; i < N; i++){
      int next;
      if(i != N-1) next = i+1;
      else next = 0;
      if(ss.at(i) == 'S'){
        if(ss.at(i-1) == 'S' && s.at(i) == 'o') ss.at(next) = 'S';
        else if(ss.at(i-1) == 'S' && s.at(i) == 'x') ss.at(next) = 'W';
        else if(ss.at(i-1) == 'W' && s.at(i) == 'o') ss.at(next) = 'W';
        else if(ss.at(i-1) == 'W' && s.at(i) == 'x') ss.at(next) = 'S';
      }
      else{
        if(ss.at(i-1) == 'S' && s.at(i) == 'o') ss.at(next) = 'W';
        else if(ss.at(i-1) == 'S' && s.at(i) == 'x') ss.at(next) = 'S';
        else if(ss.at(i-1) == 'W' && s.at(i) == 'o') ss.at(next) = 'S';
        else if(ss.at(i-1) == 'W' && s.at(i) == 'x') ss.at(next) = 'W';
      }
    }
    if(ss.at(0) == c && ss.at(N-1) == cc){
      if(s.at(0) == 'o'){
        if(ss.at(1) == ss.at(N-1)) ss.at(0) = 'S';
        else ss.at(0) = 'W';
      }
      else{
        if(ss.at(1) == ss.at(N-1)) ss.at(0) = 'W';
        else ss.at(0) = 'S';
      }
      cout << ss << endl;
      return true;
    }
    return false;
  };

  string ss;
  map<int, char> ma;
  ma[0] = 'S'; ma[1] = 'W';
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      ss = s;
      if(s.at(0) == 'o'){
        if(i == j) ss.at(0) = 'S';
        else ss.at(0) = 'W';
      }
      else{
        if(i == j) ss.at(0) = 'W';
        else ss.at(0) = 'S';
      }
      ss.at(1) =ma[i]; ss.at(N-1) = ma[j];
      if(func(ss)) return 0;
    }
  }

  cout << -1 << endl;

}