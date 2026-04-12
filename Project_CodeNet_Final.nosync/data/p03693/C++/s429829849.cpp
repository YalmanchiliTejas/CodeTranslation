#include<bits/stdc++.h>
using namespace std;
inline void rd(int &x){
  int k, m=0;
  x=0;
  for(;;){
    k = getchar_unlocked();
    if(k=='-'){
      m=1;
      break;
    }
    if('0'<=k&&k<='9'){
      x=k-'0';
      break;
    }
  }
  for(;;){
    k = getchar_unlocked();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline void wt_L(char a){
  putchar_unlocked(a);
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar_unlocked(c[i]);
  }
}
int R;
int G;
int B;
int main(){
  rd(R);
  rd(G);
  rd(B);
  if((10*G+B)%4){
    wt_L("NO");
    wt_L('\n');
  }
  else{
    wt_L("YES");
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20190721-1

// --- original code ---
// int R,G,B;
// {
//   rd(R,G,B);
//   wt( if[(10G+B)%4, "NO", "YES"] );
// }
