#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<map>
#include<numeric>
#include<set>
#include<string>
#include<utility>
#include<vector>

#define rep(i, a, n)  for(int i=a; i<n; i++)
#define per(i, a, n)  for(int i=n-1; i>=a; i--)
#define fill0(n)  setfill('0') << right << setw(n)
#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MAX 1000000000
using namespace std;
typedef long long ll;

int main(){
  int n;  cin >> n;
  vector<map<char, int>> vec(n);
  string alph = "abcdefghijklmnopqrstuvwxyz";
  string s="";
  rep(i, 0, n){
    string tmp; cin >> tmp;
    for(auto c:tmp){
      vec[i][c]++;
    }
  }
  for(auto c:alph){
    int m = 100100100;
    rep(i, 0, n){
      m = min(m, vec[i][c]);
    }
    rep(i, 0, m)  s+=c;
  }
  sort(all(s));
  cout << s << endl;
  return 0;
}