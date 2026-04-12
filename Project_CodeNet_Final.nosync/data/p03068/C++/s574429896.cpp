#include<bits/stdc++.h>
#include<queue>
#define RREP(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
#define REP(i,a) for(int (i)=0; (i)<(a); (i)++)
typedef long long ll;
using namespace std;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N,K;
  string S;
  cin>>N>>S>>K;
  char tmp=S[K-1];
  REP(i,N){
    if(S[i]!=tmp){
      S[i]='*';
    }
  }
  cout<<S;


  return 0;
}