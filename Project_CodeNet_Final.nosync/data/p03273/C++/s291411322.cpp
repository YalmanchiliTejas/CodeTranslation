#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

char A[110][110];

int main(){
  int h,w;
  cin>>h>>w;
  
  vector<char> H(h),W(w);
  char c;
  rep(i,h){
    rep(j,w){
      cin>>c;
      if(c=='#') H[i]=1,W[j]=1;
      A[i][j]=c;
    }
  }
  rep(i,h){
    if(H[i]==0) continue;
    rep(j,w){
      if(W[j]==0) continue;
      cout<<A[i][j];
    }
    cout<<endl;
  }

  return 0;
}