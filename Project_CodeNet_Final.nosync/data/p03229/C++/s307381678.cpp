#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define P pair<ll,ll> 
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,ans1=0,ans2=0;cin>>n;
  lvector A(n,0),B,C;rep(i,n) cin>>A[i];
  sort(A.begin(),A.end());
  B.emplace_back(A[0]);
  C.emplace_back(A[n-1]);
  ll cnt=1,posrb=n-1,poslb=1,posrc=n-2,poslc=0;
  while(cnt<n) {
    if(cnt<n) {
      B.emplace_back(A[posrb]);
      C.emplace_back(A[poslc]);
    }
    posrb--;poslc++;cnt++;
    if(cnt<n) {
      B.insert(B.begin(),A[posrb]);
      C.insert(C.begin(),A[poslc]);
    }
    posrb--;poslc++;cnt++;
    if(cnt<n) {
      B.emplace_back(A[poslb]);
      C.emplace_back(A[posrc]);
    }
    poslb++;posrc--;cnt++;
    if(cnt<n) {
      B.insert(B.begin(),A[poslb]);
      C.insert(C.begin(),A[posrc]);
    }
    poslb++;posrc--;cnt++;
  }
  rep(i,n-1) {
    ans1+=abs(B[i]-B[i+1]);
    ans2+=abs(C[i]-C[i+1]);
  }
  print(max(ans1,ans2));
  return 0;
}