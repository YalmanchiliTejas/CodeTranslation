#include <bits/stdc++.h>
#define FOR(I,X,Y) for(int (I)=(X);(I)<(Y);(I)++)
#define REP(I,X,Y) for(int (I)=(Y)-1;(I)>=(X);(I)--)
#define ALL(X) (X).begin(),(X).end()
#define INF 1000000007
#define LINF 1000000000000000007
typedef long long ll;
using namespace std;

//0 = 羊, 1 = 狼

int main(){
  int N;
  string s;
  cin >> N >> s;
  int a[N]={0,0},b[N]={0,1},c[N]={1,0},d[N]={1,1};
  FOR(i,2,N){
    if(s[i-1] == 'o'){
      a[i] = a[i-2] ^ a[i-1];
      b[i] = b[i-2] ^ b[i-1];
      c[i] = c[i-2] ^ c[i-1];
      d[i] = d[i-2] ^ d[i-1];
    }
    else{
      a[i] = a[i-2] ^ a[i-1] ^ 1;
      b[i] = b[i-2] ^ b[i-1] ^ 1;
      c[i] = c[i-2] ^ c[i-1] ^ 1;
      d[i] = d[i-2] ^ d[i-1] ^ 1;
    }
  }
  bool a1=0,a2=0,b1=0,b2=0,c1=0,c2=0,d1=0,d2=0;
  if(s[N-1] == 'o'){
    if(a[0] == a[N-2] ^ a[N-1])a1 = 1;
    if(b[0] == b[N-2] ^ b[N-1])b1 = 1;
    if(c[0] == c[N-2] ^ c[N-1])c1 = 1;
    if(d[0] == d[N-2] ^ d[N-1])d1 = 1;
  }
  else{
    if(a[0] == a[N-2] ^ a[N-1] ^ 1)a1 = 1;
    if(b[0] == b[N-2] ^ b[N-1] ^ 1)b1 = 1;
    if(c[0] == c[N-2] ^ c[N-1] ^ 1)c1 = 1;
    if(d[0] == d[N-2] ^ d[N-1] ^ 1)d1 = 1;
  }
  if(s[0] == 'o'){
    if(a[1] == a[N-1] ^ a[0])a2 = 1;
    if(b[1] == b[N-1] ^ b[0])b2 = 1;
    if(c[1] == c[N-1] ^ c[0])c2 = 1;
    if(d[1] == d[N-1] ^ d[0])d2 = 1;
  }
  else{
    if(a[1] == a[N-1] ^ a[0] ^ 1)a2 = 1;
    if(b[1] == b[N-1] ^ b[0] ^ 1)b2 = 1;
    if(c[1] == c[N-1] ^ c[0] ^ 1)c2 = 1;
    if(d[1] == d[N-1] ^ d[0] ^ 1)d2 = 1;
  }
  if(a1 && a2){
    FOR(i,0,N)cout << (a[i] ? 'W' : 'S');cout << endl;
    return 0;
  }
  if(b1 && b2){
    FOR(i,0,N)cout << (b[i] ? 'W' : 'S');cout << endl;
    return 0;
  }
  if(c1 && c2){
    FOR(i,0,N)cout << (c[i] ? 'W' : 'S');cout << endl;
    return 0;
  }
  if(d1 && d2){
    FOR(i,0,N)cout << (d[i] ? 'W' : 'S');cout << endl;
    return 0;
  }
  cout << -1 << endl;
}
