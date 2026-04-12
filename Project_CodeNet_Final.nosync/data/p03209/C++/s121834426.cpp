#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD=1000000007;
const long double PI=3.14159265358979;
const ll MAX=51;

ll A[MAX];
ll P[MAX];

void Do(){
  A[0]=1;P[0]=1;
  for(int i=1;i<MAX;i++){
    A[i]=A[i-1]*2+3;
    P[i]=P[i-1]*2+1;
  }
  return;
}

void bfs(ll N,ll &X,ll &ans){
  //cout<<ans<<endl;
  if(A[N]/2<X){
    ans+=P[N-1];
    ans++;
    X=X-A[N]/2;
  }
  if(A[N]/2==X){
    ans+=P[N-1];
    X=0;
  }
  if(A[N]/2>X&&X!=0){
    N--;
    X--;
    //cout<<N<<" "<<X<<" "<<ans<<endl;
    bfs(N,X,ans);
  }
  if(X==0){
    //cout<<N<<" "ans<<endl;
    return;
  }
  
}
  

int main() {
  Do();
  ll N,X;
  cin>>N>>X;
  if(A[N]==X){
    X--;
  }
  ll ans=0;
  bfs(N,X,ans);
  cout<<ans<<endl;
  //cout<<P[2];
}
