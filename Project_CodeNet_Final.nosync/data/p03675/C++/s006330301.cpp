#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

const int MOD=1000000007;
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;

int main() {
  int n; cin>>n;
  deque<ll> deq;
  
  for(int i=0;i<n;i++){
    ll a; cin>>a;
    if(i%2==0) deq.push_back(a);
    else deq.push_front(a);
  }
  
  if(n%2==0){
    for(int i=0; i<n; i++){
      cout<<deq.front()<<" ";
      deq.pop_front();
    }
  }
  else{
    for(int i=0; i<n ;i ++){
      cout<<deq.back()<<" ";
      deq.pop_back();
    }
  }
  return 0;
  
}
