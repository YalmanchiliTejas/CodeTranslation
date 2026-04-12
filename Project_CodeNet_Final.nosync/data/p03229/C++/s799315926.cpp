#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b,c;
  REP(i,n) cin >> a[i];
  VSORT(a);
  int md=n/2;
  b.push_back(a[md]);
  c.push_back(a[md]);
  REP(i,md){
    b.push_back(a[i]);
    b.push_back(a[n-1-i]);
  }

  REP(i,md){
    c.push_back(a[n-1-i]);
    c.push_back(a[i]);
  }

  ll sum1=0;
  ll sum2=0;
  
  //REP(i,n) cout << b[i] << " " << c[i] << endl;
  //return 0;
  for(int i=1;i<n;i++){
    sum1 += abs(b[i] - b[i-1]);
    sum2 += abs(c[i] - c[i-1]);
  }
  
  cout << max(sum1,sum2) << endl;
    
}