#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  ll a,b,ab,na,nb;
  cin >> a >> b >> ab >> na >> nb;
  if(a+b<ab*2) {
    cout << a*na+b*nb << endl;
  }
  else {
    ll ans=0;
    ll temp=min(na,nb);
    ans+=temp*ab*2;
    na-=temp;
    nb-=temp;
    if(a<2*ab) {
      ans+=na*a;
    }
    else {
      ans+=na*ab*2;
    }
    if(b<2*ab) {
      ans+=nb*b;
    }
    else {
      ans+=nb*ab*2;
    }
    cout << ans << endl;
  }
}