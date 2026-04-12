#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<n+1;i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end())
typedef long long ll;
typedef pair<int,int> pair;


vector<ll> A(50);
vector<ll> P(50);

ll burger(ll n,ll x){
  if(n == 0) return 1;
  if(x == 1) return 0;
  if(x <= 1+A[n-1]) return burger(n-1,x-1);
  if(x == 2+A[n-1]) return 1+P[n-1];
  if(x <= A[n]-1) return 1+P[n-1]+burger(n-1,x-2-A[n-1]);
  if(x == A[n]) return P[n];
  return 0;
}

int main(){
  ll n,x;
  cin >>n>>x;
  A[0] = 1;
  P[0] = 1;
  rep1(i,n){
    A[i] = 3+2*A[i-1];
    P[i] = 1+2*P[i-1];
  }
  cout << burger(n,x) << endl;
}