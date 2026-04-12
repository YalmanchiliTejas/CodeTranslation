#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) v.begin(), v.end()
template<class T> using V = vector<T>;

int main(){
  int n;
  while(cin>>n,n){
    V<int> a(n);
    REP(i,n) cin >> a[i];
    sort(ALL(a));
    int ans = accumulate(a.begin()+1,a.end()-1,0);
    cout << ans/(n-2) << endl;
  }
}

