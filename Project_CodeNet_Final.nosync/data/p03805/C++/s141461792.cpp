#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()

int main(){
  int N,M;
  cin>>N>>M;
  VI A(M),B(M);
  rep(i,M) cin>>A[i]>>B[i];
  VVI X(8,VI(8));
  rep(i,M){
    X[A[i]-1][B[i]-1]=1;
    X[B[i]-1][A[i]-1]=1;
  }
  if(N!=8){
    rep(i,N){
      if(i) X[i][N]=1;
    }
    rep(i,7-N){
      X[6-i][7-i]=1;
    }
  }
  int ans=0;
  rep(i,8){
    if(i==0) continue;
    if(X[0][i]==0) continue;
    rep(i2,8){
      if(i2==0||i2==i) continue;
      if(X[i][i2]==0) continue;
      rep(i3,8){
        if(i3==0||i3==i||i3==i2) continue;
        if(X[i2][i3]==0) continue;
        rep(i4,8){
          if(i4==0||i4==i||i4==i2||i4==i3) continue;
          if(X[i3][i4]==0) continue;
          rep(i5,8){
            if(i5==0||i5==i||i5==i2||i5==i3||i5==i4) continue;
            if(X[i4][i5]==0) continue;
            rep(i6,8){
              if(i6==0||i6==i||i6==i2||i6==i3||i6==i4||i6==i5) continue;
              if(X[i5][i6]==0) continue;
              rep(i7,8){
                if(i7==0||i7==i||i7==i2||i7==i3||i7==i4||i7==i5||i7==i6) continue;
                if(X[i6][i7]==0) continue;
                ans++;
              }
            }
          }
        }
      }
    }
  }
  cout<<ans<<endl;
}