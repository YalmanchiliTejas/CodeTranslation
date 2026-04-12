#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i,n) for(int i=0; i<n; i++)
#define all(x) (x).begin(),(x).end()
#define INF (1e9)

int n,m,ans=0;
char a[100],b[100];
int main(){
  cin >> n >> m;
  rep(i,m){
    cin >> a[i] >> b[i];
  }
  string s="";
  rep(i,n){
    s += to_string(i+1);
  }
  int kai=1;
  rep(i,n-1){
    kai *= i+1;
  }
  rep(i,kai){//頂点をどの順で回るかすべての組み合わせを試す

    rep(j,n-1){//頂点をたどる
      char im=s[j],tg=s[j+1];
      bool hen=false;

      rep(l,m){//2頂点を繋ぐ辺があるかどうか探す
        if((a[l]==s[j]&&b[l]==s[j+1])||(a[l]==s[j+1]&&b[l]==s[j])){
          hen=1;
        }
      }

      if(!hen){//存在しなかったらbreak
        break;
      }else{
        if(j==n-2){
          ans++;
        }
      }
    }
    //cout << ans << " " << s << endl;
    next_permutation(s.begin()+1,s.end());
  }
  cout << ans << endl;
}