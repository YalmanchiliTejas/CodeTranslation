#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define INF INT_MAX;
typedef long long ll;
using namespace std;

int main(){
  int h,w;cin >> h >>w;
  char a[h][w];
  vector<int> horizontal(h,false),vertical(w,false);
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin >> a[i][j];
      if(a[i][j]=='#'){
        vertical[j] = true;
        horizontal[i] = true;
      }
    }
  }

  for(int i=0;i<h;i++){
    if(horizontal[i]==false) continue;
    for(int j=0;j<w;j++){
      if(vertical[j]==false) continue;
      printf("%c",a[i][j]);
    }
    puts("");
  }

}