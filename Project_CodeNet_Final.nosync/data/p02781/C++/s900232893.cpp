#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define VFOR(x,a,b) for(int x=(a);x<((a)+(b));x++)
ll LLtable[110][5];
ll F(string N, int K);
int main(){
  VFOR(i,0,110){VFOR(j,0,5){LLtable[i][j]=-100;}}
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
  {
    int tmpflg = 1;
    VFOR(i,0,N.size()){
      if(N[i]!='9'){
        tmpflg = 0;
        i = -10;
      }
    }
    if(tmpflg && LLtable[N.size()][K]!=-100){
      return LLtable[N.size()][K];
    }
  }
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
  ll anstmpk = F(s9,K),anstmpk2=F(s9,K-1);
  if(LLtable[s9.size()][K]==-100) LLtable[s9.size()][K] = anstmpk;
  if(LLtable[s9.size()][K-1]==-100) LLtable[s9.size()][K-1] = anstmpk2;
  ll ans=( anstmpk+(N[0]-'0'-1)*anstmpk2+F(sl,K-1) );
  //cout << "F( " << N << ", " << K << ") = " << ans << endl;
  return ( ans );
}