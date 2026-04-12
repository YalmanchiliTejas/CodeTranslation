#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N; cin>>N;
  vector<ll> A(N,0), O(N+1,0), DP(N+1,-1e15);
  for(int i=0; i<N; i++){
    ll a; cin>>a; A[i]=a;
    if(i%2==0) O[i+1]=a;
    if(i<=2) DP[i+1]=max(DP[i],a);
    //DP[4]、2個とる。DP[2]+aかO[1]+O[3]
    //DP[5]、2個とる。DP[4]かDP[3]+a
    //DP[6]、3個とる。DP[4]+aかO[1]+O[3]+O[5](aを使わないとなると奇数番目をとるだけ）
    //DP[7]、3個とる。DP[6]かDP[5]+a
  }
  //奇数累積和
  for(int i=1; i<=N; i++) O[i]=O[i-1]+O[i];
  //DPつくる
  for(int i=4; i<=N; i++){
    if(i%2==0) DP[i]=max(DP[i-2]+A[i-1], O[i-1]);
    else DP[i]=max(DP[i-1],DP[i-2]+A[i-1]);
  }
  cout<<DP[N]<<endl;
}
