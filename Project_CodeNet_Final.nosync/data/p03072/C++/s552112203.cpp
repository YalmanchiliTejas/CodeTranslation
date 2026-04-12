#include <bits/stdc++.h>
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define pb push_back
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ll long long
using namespace std;
int main(){
  int n;
  cin >> n;
  int m = 0, cnt = 0;
  REP(i,n){
    int a;
    cin >> a;
    if(a >= m){
      cnt++; 
    }
    m = max(m, a);
  }
  cout << cnt << endl;
  return 0;
}
