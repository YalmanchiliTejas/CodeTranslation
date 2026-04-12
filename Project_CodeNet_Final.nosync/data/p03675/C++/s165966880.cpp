#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>

#define rep(i,n) for(int i = 0; i < n; ++i)
#define reps(i,f,n) for(int i = f; i <= n; ++i)
#define eb emplace_back
#define all(x) x.begin(), x.end()

using namespace std;
using PII=pair<int,int>;
using PPI=pair<int,PII>;


int main(void){
  int n;
  deque<int> d;
  vector<int> A;
  cin >> n;
  A.resize(n);
  for(auto& a: A) cin >> a;
  rep(i,n){
    if(i%2){
      d.push_front(A[i]);
    }else{
      d.push_back(A[i]);
    }
  }

  if(n%2){
    for(int i = n-1; i >= 0; --i){
      if(i != n-1) cout << " ";
      cout << d[i];
    }
  }else{
    rep(i,n){
      if(i != 0) cout << " ";
      cout << d[i];
    }
  }
  cout << endl;
  

  return 0;
}
