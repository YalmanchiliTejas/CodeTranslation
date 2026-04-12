#include <bits/stdc++.h>
#define rep(i,m,n) for(int i=m;i<n;i++)
#define c(n) cin>>n
#define c2(n,m) cin>>n>>m
#define c3(n,m,k) cin>>n>>m>>k
#define c4(n,m,k,l) cin>>n>>m>>k>>l
#define co(n) cout<<n<<endl
using namespace std;

int main(){
  long a=0,b,c=0,d=0,e,n;
  c2(a,b);
  char s[a][b];
  string ans="Possible";
  rep(i,0,a) rep(j,0,b) c(s[i][j]);
  s[c][d]='.';
  
  while(1){
    if(c<a && s[c+1][d]=='#' && d<b && s[c][d+1]=='#'){
      ans="Impossible";
      break;
    }
    
    else if(c>0 && s[c-1][d]=='#'){
      ans="Impossible";
      break;
    }
    else if(d>0 && s[c][d-1]=='#'){
      ans="Impossible";
      break;
    }
    else if(c<a && s[c+1][d]=='#'){
      c++;
      s[c][d]='.';
      continue;
    }
    else if(d<b && s[c][d+1]=='#'){
      d++;
      s[c][d]='.';
      continue;
    }
    if(c==a-1 && d==b-1) break;
    
  }
  co(ans);
    
  return 0;
}
