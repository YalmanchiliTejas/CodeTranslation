#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <functional>
#include <sstream>
#include <bitset>
#include <map>

using namespace std;

typedef long long ll;

ll pcount (vector<ll>& len, vector<ll>& pnum, ll x, ll cur) {
  if (x <= 0) return 0;
  if (cur==0) return 1;
  ll sum;
  sum = 0;
  if (x == 2*len[cur-1]+3) sum += 2*pnum[cur-1]+1;
  else if (x > len[cur-1] + 2) {
    sum += pnum[cur-1] + 1;
    sum += pcount(len,pnum,x - len[cur-1] - 2,cur-1);
  } else if (x == len[cur-1] + 2) {
    sum += pnum[cur-1] + 1;
  } else if (x > 1){
    sum += pcount(len,pnum,x-1,cur-1);
  }
  return sum;
}

int main() {
  ll N,X;
  cin>>N>>X;
  vector<ll> len,pnum;
  len.push_back(1);
  pnum.push_back(1);
  for (ll i = 1; i <= N; i++) len.push_back(2*len[i-1]+3);
  for (ll i = 1; i <= N; i++) pnum.push_back(2*pnum[i-1]+1);
  ll ans;
  ans = pcount(len,pnum,X,N);
  cout<<ans<<endl;
  return 0;
}