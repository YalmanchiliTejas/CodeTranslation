#include <bits/stdc++.h>
using namespace std;
 
int N;
string S;
 
//0がSで1がW
 
vector<int> zoo(int i,int j){
  vector<int> T(N+1);
  T[0]=i,T[1]=j;
  for(int i=1;i<N;++i){
    if(S[i]=='o' && T[i]==0) T[i+1]=T[i-1];
    if(S[i]=='o' && T[i]==1) T[i+1]=1-T[i-1];
    if(S[i]=='x' && T[i]==0) T[i+1]=1-T[i-1];
    if(S[i]=='x' && T[i]==1) T[i+1]=T[i-1];
  }
 
  return T;
}
 
bool check(vector<int> T){
  if(T[0]==0){
    if(S[0]=='o' && T[N-1]==T[1]) return true;
    if(S[0]=='x' && T[N-1]!=T[1]) return true;
    else return false;
  }
    if(T[0]==1){
    if(S[0]=='o' && T[N-1]==T[1]) return false;
    if(S[0]=='x' && T[N-1]!=T[1]) return false;
    else return true;
  }
}
 
 
int main(){
  cin>>N;
  cin>>S;
  bool frag=false;
  for(int i=0;i<2;++i){
    for(int j=0;j<2;++j){
      vector<int> T(N+1);
      T=zoo(i,j);
      if(T[0]==T[N] && check(T)){
        for(int i=0;i<N;++i){
          if(T[i]) cout<<'W';
          else cout<<'S';
        }
        cout<<endl;
        frag=true;
      }
      if(frag) break;
    }
    if(frag) break;
  }
 
  if(!frag) cout<<-1<<endl;
 
}