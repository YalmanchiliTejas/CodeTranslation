#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 2e9;
const int MOD = 1000000007;

 
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a.at(i);
  deque<int> dq;
  rep(i,n){
    int idx = lower_bound(dq.begin(),dq.end(),a.at(i)) - dq.begin();
    //cout << idx << endl;
    if(idx == 0) dq.push_front(a.at(i));
    else if(idx == dq.size() ) dq.back() = a.at(i);
    else dq.at(idx-1) = a.at(i);
  }
  cout << dq.size() << endl;
  return 0;
}

