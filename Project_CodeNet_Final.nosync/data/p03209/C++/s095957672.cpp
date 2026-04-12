#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VRSORT(v) sort(v.rbegin(), v.rend());//vectorの降順ソート
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
const int MOD = 1000000009;

using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

int64_t len[51], pat[51];

int64_t rec(int64_t k,int64_t x){
  
    if(x == len[k]) return pat[k];
  
    int64_t ans = 0;

	x--;
  	
  	if(x > 0){
      int64_t l = min(x,len[k-1]);
      ans+= rec(k-1, l);
      x-=l;
    }
  
  	if(x>0){
      ans++;
      x--;
    }
  
  	if(x > 0){
      int64_t l = min(x,len[k-1]);
      ans+= rec(k-1, l);
      x-=l;
    }
  
  return ans;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int64_t n,x;
  cin >> n >> x;
  len[0] = pat[0] = 1;
  for(int i=1;i<=n;i++){
    len[i] = len[i-1] * 2 + 3;
    pat[i] = pat[i-1] * 2 + 1;
  }
  
  cout << rec(n,x) << endl;
}