#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <unordered_map>
#define rep(i,n) for (int i=0; i<n;++i)
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
int N;
priority_queue<ll, vector<ll>, greater<ll> > asc_que;
priority_queue<ll> desc_que;
priority_queue<ll, vector<ll>, greater<ll> > asc_que2;
priority_queue<ll> desc_que2;

ll calc(){
  ll left = asc_que.top();
  ll right = asc_que.top();
  asc_que.pop();
  bool flag = true;
  ll ans = 0;
  int cnt = 0;
  rep(i, N-1){
    ll a = 0;
    if (flag){
      a = desc_que.top();
      desc_que.pop();
    }else{
      a = asc_que.top();
      asc_que.pop();
    }
    if (cnt==0){
      ans += abs(a-left);
      left = a;
    }
    if (cnt==1){
      ans += abs(a-right);
      right = a;
    }
    cnt++;
    if (cnt==2){
      flag = !flag;
      cnt = 0;
    }
  }
  return ans;
}

ll calc2(){
  ll left = desc_que2.top();
  ll right = desc_que2.top();
  desc_que2.pop();
  bool flag = false;
  ll ans = 0;
  int cnt = 0;
  rep(i, N-1){
    ll a = 0;
    if (flag){
      a = desc_que2.top();
      desc_que2.pop();
    }else{
      a = asc_que2.top();
      asc_que2.pop();
    }
    if (cnt==0){
      ans += abs(a-left);
      left = a;
    }
    if (cnt==1){
      ans += abs(a-right);
      right = a;
    }
    cnt++;
    if (cnt==2){
      flag = !flag;
      cnt = 0;
    }
  }
  return ans;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  ll a;
  rep(i, N){
    cin >> a;
    asc_que.push(a);
    desc_que.push(a);
    asc_que2.push(a);
    desc_que2.push(a);
  }
  ll ans1 = calc();
  ll ans2 = calc2();


  cout << max(ans1, ans2) << "\n";
  return 0;
}