#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,n) for(int i = 1; i < n; i++)
#define repll(i,n) for(ll i = 0; i < n; i++)
#define REPll(i,n) for(ll i = 1; i < n; i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define yesorno(a) printf(a ? "yes\n" : "no\n")
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define YESorNO(a) printf(a ? "YES\n" : "NO\n") 
#define endl "\n"
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
using vi = vector<int>;
using vii = vector<vi>;
using vl = vector<ll>;
using vll = vector<vl>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll a, const ll b){return ((a)+(b)-1)/b;}


signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<string> s(n);
  rep(i,n) {
    cin >> s[i];
  }
  for(char i = 'a'; i <= 'z'; i++){
    int cnt = inf;
    rep(j,n){
      int tmp = 0;
      rep(k,s[j].size()) {
        if(s[j][k] == i) tmp++;
      }
      cnt = min(cnt, tmp);
    }
    rep(j,cnt) cout << i;
  }
  cout << endl;
}