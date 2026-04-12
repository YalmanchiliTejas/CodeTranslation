#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#define vll vector<ll>
#define vvvl vector<vvl>
#define vvl vector<vector<ll>>
#define vvul vector<vector<ull>>
#define VV(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define VVV(a, b, c, d) vector<vvl>(a, vvl(b, vll (c, d)));
#define re(c, b) for(ll c=0;c<b;c++)
#define all(obj) (obj).begin(), (obj).end()
typedef long long int ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

ll n;
vll s, t;
void err(){
  std::cout << -1 << '\n';
  exit(0);
}

bool check(vll U, vll V, vvl ret){
  re(i, n){
    bool f = true;
    if(s[i]==0){
      int tmp = 1;
      re(j, n) tmp &= ret[i][j];
      if(tmp!=U[i]) f = false;
    }else{
      int tmp = 0;
      re(j, n) tmp |= ret[i][j];
      if(tmp!=U[i]) f = false;
    }
    if(t[i]==0){
      int tmp = 1;
      re(j, n) tmp &= ret[j][i];
      if(tmp!=V[i]) f = false;
    }else{
      int tmp = 0;
      re(j, n) tmp |= ret[j][i];
      if(tmp!=V[i]) f = false;
    }
    if(!f) return false;
  }
  return true;
}
vvl solve(vll U, vll V, bool d){
  if(n==1){
    if(check(U, V, vvl{vll{1}})) return vvl{vll{1}};
    if(check(U, V, vvl{vll{0}})) return vvl{vll{0}};
    err();
  }

  vll row_use(n, -1);
  vll col_use(n, -1);
  bool row0 = false, row1 = false, col0 = false, col1 = false;
  vvl ret = VV(n, n, -1, ll);
  re(i, n) {
    if(s[i]==0&&U[i]==1){
      re(j, n){
        if(ret[i][j]==0) err();
        else ret[i][j] = 1;
      }
      row1 = true;
      row_use[i] = 1;
    }
    if(s[i]==1&&U[i]==0){
      re(j, n){
        if(ret[i][j]==1) err();
        else ret[i][j] = 0;
      }
      row0 = true;
      row_use[i] = 0;
    }
  }
  re(i, n){
    if(t[i]==0&&V[i]==1){
      re(j, n){
        if(ret[j][i]==0) err();
        else ret[j][i] = 1;
      }
      col1 = true;
      col_use[i] = 1;
    }
    if(t[i]==1&&V[i]==0){
      re(j, n){
        if(ret[j][i]==1) err();
        else ret[j][i] = 0;
      }
      col0 = true;
      col_use[i] = 0;
    }
  }
  //クロス
  if((row0&&col0)||(row1&&col1)){
    // 0クロスと1クロスは共存しない
    bool f = (row0&&col0);
    re(i, n) re(j, n) if(ret[i][j]==-1) ret[i][j] = (f?1:0);
  }else if(row0||row1||col0||col1){
    if(row0&&row1){
      re(i, n) re(j, n) if(ret[i][j]==-1) ret[i][j] = (j%2);
    }else if(col0&&col1){
      re(i, n) re(j, n) if(ret[j][i]==-1) ret[j][i] = (j%2);
    }else if(row0){
      re(i, n){
        if(row_use[i]!=-1) continue;
        if(s[i]==1&&U[i]==1) {
          re(j, n){
            col_use[j] = 999999;
            ret[i][j] = 1;
          }
        }else{
          bool z = false;
          re(j, n){
            if((t[j]==0&&V[j]==0)||col_use[j]!=-1) {
              z = true;
              col_use[j] = 99999;
              ret[i][j] = 0;
              break;
            }
          }
          if(z) {
            re(j, n) if(ret[i][j]==-1) ret[i][j] = 1, col_use[j] = 99999;
          }else{
            ret[i][0] = 0;
            for(int j=1;j<n;j++) if(ret[i][j]==-1) ret[i][j] = 1, col_use[j] = 99999;
          }
        }
      }
    }else if(row1){
      re(i, n){
        if(row_use[i]!=-1) continue;
        if(s[i]==0&&U[i]==0) {
          re(j, n){
            col_use[j] = 999999;
            ret[i][j] = 0;
          }
        }else{
          bool z = false;
          re(j, n){
            if((t[j]==1&&V[j]==1)||col_use[j]!=-1) {
              z = true;
              col_use[j] = 99999;
              ret[i][j] = 1;
              break;
            }
          }
          if(z) {
            re(j, n) if(ret[i][j]==-1) ret[i][j] = 0, col_use[j] = 99999;
          }else{
            ret[i][0] = 1;
            for(int j=1;j<n;j++) if(ret[i][j]==-1) ret[i][j] = 0, col_use[j] = 99999;
          }
        }
      }
    }else if(col0){
      re(i, n){
        if(col_use[i]!=-1) continue;
        if(t[i]==1&&V[i]==1) {
          re(j, n){
            row_use[j] = 999999;
            ret[j][i] = 1;
          }
        }else{
          bool z = false;
          re(j, n){
            if((s[j]==0&&U[j]==0)||row_use[j]!=-1) {
              z = true;
              row_use[j] = 99999;
              ret[j][i] = 0;
              break;
            }
          }
          if(z) {
            re(j, n) if(ret[j][i]==-1) ret[j][i] = 1, row_use[j] = 99999;
          }else{
            ret[0][i] = 0;
            for(int j=1;j<n;j++) if(ret[j][i]==-1) ret[j][i] = 1, row_use[j] = 99999;
          }
        }
      }
    }else if(col1){
      re(i, n){
        if(col_use[i]!=-1) continue;
        if(t[i]==0&&V[i]==0) {
          re(j, n){
            row_use[j] = 999999;
            ret[j][i] = 0;
          }
        }else{
          bool z = false;
          re(j, n){
            if((s[j]==1&&U[j]==1)||row_use[j]!=-1) {
              z = true;
              row_use[j] = 99999;
              ret[j][i] = 1;
              break;
            }
          }
          if(z) {
            re(j, n) if(ret[j][i]==-1) ret[j][i] = 0, row_use[j] = 99999;
          }else{
            ret[0][i] = 1;
            for(int j=1;j<n;j++) if(ret[j][i]==-1) ret[j][i] = 0, row_use[j] = 99999;
          }
        }
      }
    }
  }else{
    re(i, n) re(j, n) ret[i][j] = (i+j)%2;
  }
  if(d){
    re(i, n){
      re(j, n) std::cout << ret[i][j] << " ";
      std::cout << '\n';
    }
  }
  // check
  if(!check(U, V, ret)) err();
  return ret;
}

int main(int argc, char const *argv[]) {
  std::cin >> n;
  vector<ull> u(n), v(n);
  s.resize(n);
  t.resize(n);
  re(i, n) std::cin >> s[i];
  re(i, n) std::cin >> t[i];
  re(i, n) std::cin >> u[i];
  re(i, n) std::cin >> v[i];

  vvul ans = VV(n, n, 0, ull);
  vector<ull> t(64, 1);
  for(int i=1;i<64;i++) t[i] = t[i-1]*2;

  for(int i=0;i<64;i++){
    vll U(n), V(n);
    re(j, n) U[j] = (u[j] >> i)&1;
    re(j, n) V[j] = (v[j] >> i)&1;

    /*
    if(i==5) {
      std::cout << U[0] << " " << U[1] << '\n';
      std::cout << V[0] << " " << V[1] << '\n';
    }
    */
    //std::cout << i << '\n';
    vvl ans_i = solve(U, V, false);
    for(int j=0;j<n;j++){
      for(int k=0;k<n;k++){
        ans[j][k] += (ull)(ans_i[j][k])*t[i];
      }
    }
  }
  re(i, n) re(j, n) std::cout << ans[i][j] << (j==n-1?"\n":" ");
  return 0;
}
