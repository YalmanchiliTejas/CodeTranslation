#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <time.h>
#include <list>

using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define reps(x,c) for(auto x:c)
#define all(x) begin(x), end(x)
#define pb(a) emplace_back(a) 
#define mp(a,b) make_pair((a),(b))
#define pl pair<ll,ll>
#define INF 2147483600
#define MOD 1000000007
#define fi first
#define se second
#define dbg(x) cout << #x"="<< (x) << endl
#define dbgv(x) cout<<#x<<endl;reps(y,x){cout<<y<<" ";}cout<<endl

int main(){
  // 貪欲法
  ll n;cin>>n;
  vector<ll> a(n);
  rep(i,n){
    cin>>a[i];
  }
  sort(all(a));
  deque<ll> ans;
  ll head_cnt=1,back_cnt=1;
  ans.pb(a[0]);
  ans.pb(a[n-1]);
  vector<int> temp(4);
  ll ans_num=abs(a[0]-a[n-1]);
  rep(i,n-2){
    temp[0]=abs(a[head_cnt]-ans.front());
    temp[1]=abs(a[n-1-back_cnt]-ans.front());
    temp[2]=abs(a[head_cnt]-ans.back());
    temp[3]=abs(a[n-1-back_cnt]-ans.back());
    auto maxIt = max_element(temp.begin(), temp.end());
    size_t maxIndex = distance(temp.begin(), maxIt);
    if(maxIndex==0){
      ans.push_front(a[head_cnt]);
      head_cnt++;
      ans_num+=temp[maxIndex];
    }else if(maxIndex==1){
      ans.push_front(a[n-1-back_cnt]);
      back_cnt++;
      ans_num+=temp[maxIndex];
    }else if(maxIndex==2){
      ans.pb(a[head_cnt]);
      head_cnt++;
      ans_num+=temp[maxIndex];
    }else{
      ans.pb(a[n-1-back_cnt]);
      back_cnt++;
      ans_num+=temp[maxIndex];
    }
  }
  cout<<ans_num<<endl;
  return 0;
}