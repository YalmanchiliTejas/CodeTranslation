#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll N,a,sum=0,X=0,Y;
  cin >> N;
  vector<ll> A; 
  for(ll i=0;i<N;i++){
    cin >> a;
    A.push_back(a);
    X += a;
  }
  for(ll i=N;i>1;i--){
    X -= A[i-1];
    Y = X%1000000007;
    sum += Y*A[i-1];
    sum %=1000000007;
  }
  cout << sum;
}