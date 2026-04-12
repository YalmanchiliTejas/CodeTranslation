#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

#define SZ(a) int((a).size())
#define _REP(_1,_2,_3,_4,name,...) name
#define _REP4(i,b,e,s) for(decltype(e) _b=(b),_e=(e),i=_b+(0<(s)?0:(s));(0<(s)?i<_e:_e<=i);i+=(s))
#define _REP3(i,b,e) for(decltype(e) _b=(b),_e=(e),i=(_b<_e?_b:_b-1);(_b<_e?i<_e:_e<=i);(_b<_e?i++:i--))
#define _REP2(i,n) for(decltype(n) i=0,_n=(n);i<_n;i++)
#define _REP1(n) for(decltype(n) _i=0,_n=(n);_i<_n;_i++)
#define REP(...) _REP(__VA_ARGS__,_REP4,_REP3,_REP2,_REP1)(__VA_ARGS__)
#define FOR(it,c) for(auto&& it=begin(c);it!=end(c);it++)
#define ROF(it,c) for(auto&& it=rbegin(c);it!=rend(c);it++)
#define INT(n) int n;scanf("%d",&n)
#define AI(a,size,n) array<int,size> a;REP(i,n){scanf("%d",&a[i]);}
#define VS(v,n) vector<string> v(n);REP(i,n){cin>>v[i];}
#define MSET(arr,val)  memset(arr,val,sizeof(arr))

int main(){
  INT(h); INT(w); VS(as, h);
  int r = 0, c = 0, cnt = 0;
  while (r < h && c < w){
    if (as[r][c] == '.'){break;}
    else {as[r][c] = '.';}
    if (c < w - 1 && as[r][c + 1] == '#'){
      c++;
    }
    else if (r < h - 1 && as[r + 1][c] == '#'){
      r++;
    }
  }
  REP(i, h){REP(j, w){if (as[i][j] == '#'){cnt++;}}}
  if (cnt == 0){printf("Possible\n");}
  else{printf("Impossible\n");}
  return 0;
}
