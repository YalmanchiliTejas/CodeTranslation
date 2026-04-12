#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int N,Q;
  cin>>N;
  Q=N/15;
  cout<<N*800-Q*200<<endl;
  return 0;
}