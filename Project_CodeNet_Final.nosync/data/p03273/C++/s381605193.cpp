// A

#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll MOD=1e9+7;
#define pa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};

int main(){
  int H,W;
  string s[100];
  cin>>H>>W;
  for (int i(0);i<H;i++) cin>>s[i];
  int yoko[100]={0},tate[100]={0};
  for (int i(0);i<H;i++){
    bool flag = true;
    for (int j(0);j<W;j++){
      if (s[i][j] == '#') flag = false;
    }
    if (flag) yoko[i]++;
  }

  for (int i(0);i<W;i++){
    bool flag = true;
    for (int j(0);j<H;j++){
      if (s[j][i] == '#') flag = false;
    }
    if (flag) tate[i]++;
  }

  for (int i(0);i<H;i++){
    for (int j(0);j<W;j++){
      if (yoko[i] == 0 && tate[j] == 0){
        cout << s[i][j];
      }
    }
    if (yoko[i] == 0) cout << endl;
  }
  return 0;
}

