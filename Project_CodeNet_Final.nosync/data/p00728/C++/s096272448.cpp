#include<bits/stdc++.h>
typedef long long ll;
#define REP(i,n) for(int i = 0;i < (n);i++)
#define rep(i,m,n) for(int i = (m);i < (n);i++)
#define P pair<int,int>
#define pb push_back
#define mk make_pair
using namespace std;
#define Vec(a) vector <int> a
const int INF = 1 << 20;
const int MOD = 1e9+7;





int main(){
  int n;
  while(cin >> n,n){
    vector <ll> a(n);
    REP(i,n)
      cin >> a[i];
    sort(a.begin(),a.end());
    ll sum = 0;
    rep(i,1,a.size()-1){
      sum += a[i];
    }
    cout << sum/(n-2) << endl;
  }
  return 0;
}

