#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main(){
  int N,Q;
  int A[114514],B[114514];
  cin >> N >> Q;
  vector<int>V;
  REP(i,Q){
    cin >> A[i] >> B[i];
  }
  V.assign(N+2,0);
  /*V[1] = 2;
  REP(i,Q){
    if(V[A[i]]==2){
      V[B[i]]=max(V[B[i]],2);
      V[B[i]+1]=max(V[B[i]+1],1);
      V[B[i]-1]=max(V[B[i]-1],1);
      V[A[i]]=max(V[B[i]],0);
    }
    else if(V[A[i]]==1||V[A[i]+1]==2||V[A[i]-1]==2){
      V[B[i]]=max(V[B[i]],1);
    }
    V[0]=0;
    V[N+1]=0;
  }*/
  V[1]=2;
  V[2]=1;
  int now=1;//2はここにいる
  REP(i,Q){
    swap(V[A[i]],V[B[i]]);
    if(A[i]==now){
      now=B[i];
    }else if(B[i]==now){
      now=A[i];
    }
    V[now-1]=1;
    V[now+1]=1;


  }
  int ans=0;
  for(int i=1;i<=N;i++){
    //cout<<V[i]<<endl;
    if(V[i]>0)ans++;
  }
  cout<<ans<<endl;
  return 0;
}
