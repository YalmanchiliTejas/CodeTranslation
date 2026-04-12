#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
typedef long long ll;
#define MOD 1000000007

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll INF = 1LL << 60;



//大文字小文字気をつけろ

int main(){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;

  if(x<y){
     swap(a,b);
     swap(x,y);
  }

  if(a+b>c*2){
    cout << min(c*2*x,c*2*y+a*(x-y)) << endl;
  }else{
    cout << a*x+b*y << endl;
  }


}
