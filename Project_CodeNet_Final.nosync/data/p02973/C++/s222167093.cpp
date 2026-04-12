#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define ll long long
int main(){
  int N;
  cin>>N;
  vector<int> A(N),B(N);
  rep(i,N) cin>>A[i];
  rep(i,N) A[i]=-A[i];
  rep(i,N) B[i]=1000000010;
  rep(i,N) *upper_bound(all(B),A[i])=A[i];
  cout<<lower_bound(all(B),1000000010)-B.begin()<<endl;
}