#include <bits/stdc++.h>
using namespace std;

// ABCテンプレート

#define rep(i,n) for (int i = 0; i<(n); i++)
#define in(n) cin >> (n)
#define out(ans) cout << (ans) << endl;
#define keta(n) cout << fixed << setprecision((n));
using ll = int64_t;
using v = vector<int>;


int main() {
  ll N;
  ll A, ans=0;
  cin >> N;
  vector<ll> sumlist(N), alist(N);
  for(ll i=0; i<N; i++) {
    if(i==0) {
      cin >> A;
      sumlist.at(i)=A;
      alist.at(i)=A;
    }
    else {
      cin >> A;
      sumlist.at(i) = (sumlist.at(i-1)+A)%(1000000000+7);
      alist.at(i)=A;
    }
  }
  for(ll i=0; i<N-1; i++) {
    if(sumlist.at(N-1)-sumlist.at(i)>=0) {
      ans += (alist.at(i)*(sumlist.at(N-1)-sumlist.at(i)))%(1000000000+7);
    }
    else {
      ans += (alist.at(i)*(sumlist.at(N-1)-sumlist.at(i)+1000000000+7))%(1000000000+7);
    }
  }
  cout << ans%(1000000000+7);
}