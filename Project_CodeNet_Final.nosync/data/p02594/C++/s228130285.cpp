#include<bits/stdc++.h>
using namespace std;
template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }
typedef long long ll;
typedef vector<int> vint;
typedef pair<int, int> pint;
typedef vector<long long> vlong;
typedef vector<string> vstring;
#define vpush(a,x) a.push_back(x);
#define rep(i, n) REP(i, 0, n)
#define all(v) v.begin(), v.end()
#define REP(i, x, n) for(int i = x; i < n; i++)
const int INF = 1 << 30;
const int dx[] = {1,0,-1,0,1,1,-1,-1};
const int dy[] = {0,-1,0,1,1,-1,-1,1};
#define stp(x)  setprecision(x)
int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int x;
  cin>>x;
  if(x>=30){
    cout<<"Yes"<<'\n';
  }
  else{
    cout<<"No"<<'\n';
  }
  return(0);
}
