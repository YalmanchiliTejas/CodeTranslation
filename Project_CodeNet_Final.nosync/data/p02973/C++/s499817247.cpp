#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
typedef pair<ll,ll> pll;

#define reps(i,f,n) for(int i = int(f); i <= int(n); i++)
#define rep(i,n) reps(i,0,int(n)-1)
#define rrep(i,n) for(int i = n-1; i >= 0; i--)

#define all(x) (x).begin(),(x).end()
#define X first
#define Y second

#define sz size()
#define eb emplace_back
#define pb push_back

vector<int> a;

int main(void){
  int n;
  cin >> n;
  a.resize(n);
  multiset<int> s;
  rep(i, n){
    cin >> a[i];
  }
  for(int i  = n - 1; i >= 0 ; --i){
    auto x = s.upper_bound(a[i]);
    if (x != s.end()){
      s.erase(x);
    }
    s.insert(a[i]);
  }

  cout << s.size() << endl;
  return 0;
}

