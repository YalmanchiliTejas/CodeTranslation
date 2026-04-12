#include<bits/stdc++.h>
using namespace std;
#define int long long

int len[51],pat[51];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,x; cin >> n >> x;

  len[0] = pat[0] = 1;
  for(int i = 1; i <= n; i++){
    len[i] = len[i-1] * 2 + 3;
    pat[i] = pat[i-1] * 2 + 1;
  }

  function< int(int,int) > rec =
  [&](int k,int x){ //{レベル,食べる層}
    if(x == len[k]) return pat[k];

    int ans = 0;
    //下のバン
    x--;
    //下のk-1バーガー
    if(x > 0){
      int l = min(x,len[k-1]);
      ans += rec(k-1,l);
      x -= l;
    }
    //真ん中のパティ
    if(x > 0){
      ans++;
      x--;
    }
    //上のk-1バーガー
    if(x > 0){
      int l = min(x,len[k-1]);
      ans += rec(k-1,l);
      x -= l;
    }
    return ans;
  };
  cout << rec(n,x) << endl;

  return 0;
}
