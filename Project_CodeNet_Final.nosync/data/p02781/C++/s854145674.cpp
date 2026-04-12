#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define VFOR(x,a,b) for(int x=(a);x<((a)+(b));x++)
ll F(string N, int K);
int main(){
  string N; int K;
  cin >> N >> K;
  cout << F(N,K);
  return 0;
}
ll F(string N, int K){
  if(K==0) return 1;
  if(N.size()<K) return 0;
  if(N.size()==0) return 0;
  if(N.size()==1) return (N[0]-'0');
  string s9,sl;
  VFOR(i,0,N.size()-1) {
    s9 += '9';
  }
  VFOR(i,1,N.size()-1){
    if(N[i]!= '0'){
      while(i<N.size()){
        sl += N[i];
        i++;
      }
      i = -10;
    }
  }
  ll ans=( F(s9,K)+(N[0]-'0'-1)*F(s9,K-1)+F(sl,K-1) );
  //cout << "F( " << N << ", " << K << ") = " << ans << endl;
  return ( ans );
}