#include<iostream>
using namespace std;

int main(){
  int n,a,b,c,x;
  while(cin >> n >> a >> b >> c >> x, c){
    int pic[n+1];
    for(int i=0; i<n; ++i){
      cin >> pic[i];
    }
    int cnt = 0;
    int ans = 0;
    for(; ans<=10000; ++ans){
      if(x==pic[cnt]){
        ++cnt;
        if(cnt==n){
          break;
        }
      }
      x = (a*x+b)%c;
    }
    if(ans>10000){
      cout << -1 << endl;
    }else{
      cout << ans << endl;
    }
  }
  return 0;
}

