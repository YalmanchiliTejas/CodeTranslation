#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  ll n;
  int x,m;
  cin >> n >> x >> m;

  vector<int> check(m+5,0);
  vector<ll> suma(m+5,0);
  vector<ll> a(m+5);
  a.at(1) = x;
  suma.at(1) = x;
  check.at(x) = 1;

  int loop = 0;
  int first = 0;
  ll loopsum = 0;
  ll firstsum = 0;
  
  for(int i=2; i<=m+5; i++){
    a.at(i) = a.at(i-1)*a.at(i-1);
    if(a.at(i)>=m) a.at(i)%=m;
    //cout << a.at(i) << endl;
    if(check.at(a.at(i))==0) {
      check.at(a.at(i)) = i;
      suma.at(i)=suma.at(i-1)+a.at(i); 
    }else{
      loop = i-check.at(a.at(i));
      first = max(0, check.at(a.at(i))-1);
      loopsum = suma.at(i-1)-suma.at(first);
      firstsum = suma.at(first);
      break;
    }
  }

  int k = first;
  if(n<first) k=n;
  ll p = (n-k)/loop;
  ll r = n-k-loop*p;
  if(r<0) r=0;
  ll ans = suma.at(k) + loopsum*p + suma.at(first+r) - suma.at(first);
  cout << ans;
  
}