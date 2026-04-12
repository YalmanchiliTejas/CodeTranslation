#include "bits/stdc++.h"
using namespace std;

#define ul unsigned long long
#define ll long long

int main()
{
  ll a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  c*=2;

  ll maxc=max(x,y),cp,ct=LLONG_MAX;
  for (ll i=0;i<=maxc;i++) {
    cp = c * i + max(x - i, 0LL) * a + max(y - i, 0LL) * b;
    ct = min(ct, cp);
  }

  cout<<ct<<endl;

  return 0;
}


