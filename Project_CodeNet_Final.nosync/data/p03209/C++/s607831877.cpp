#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using pii = pair<int, int>;
#define fix10 cout << fixed << setprecision(10);
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define MOD 1000000007

long search(long n, long x, vector<long> &f, vector<long> &p){
  if(x <= 1){
    if(n != 0) return 0;
    else return 1;
  }
  if(2 <= x && x <= 1 + f.at(n-1)) return search(n-1,x-1,f,p);
  if(x == 2 + f.at(n-1)) return p.at(n-1) + 1;
  if(3 + f.at(n-1) <= x && x <= f.at(n) - 1 ) return p.at(n-1)+1+search(n-1,x-2-f.at(n-1),f,p);
  if(x == f.at(n)) return 2*p.at(n-1)+1;
}

int main(){
  long n,x;
  cin >> n >> x;
  vector<long> level(n+1);
  vector<long> paty(n+1);
  level.at(0) = 1;
  paty.at(0) = 1;
  rep(i,n){
    level.at(i+1) = 3 + 2*level.at(i);
    paty.at(i+1) = 1 + 2*paty.at(i);
  }
  cout << search(n,x,level,paty) << endl;
}