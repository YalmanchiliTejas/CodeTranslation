#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int N;
  cin>>N;
  vector<int> A(N);
  rep(i,N)cin>>A[i];
  int H=A[0];
  int co=0;
  rep(i,N){
    if(H<=A[i]){
      co++;
      H=A[i];
    }
  }
  cout<<co<<endl;
}