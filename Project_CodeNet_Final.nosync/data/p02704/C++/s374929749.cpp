// ※※※ 解答不能 ※※※
// Kmcode氏.
// https://atcoder.jp/contests/abc164/submissions/12391952
#include <bits/stdc++.h>
using namespace std;
using ULL = unsigned long long int;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define MAX 505
int n, ty_r[MAX], ty_c[MAX], emp[MAX];
ULL val_r[MAX], val_c[MAX], ans[MAX][MAX];
bool tmp[MAX][MAX];

void transpose(){
    rep(i, n){
        rep(j, i) swap(tmp[i][j], tmp[j][i]);
        swap(val_r[i], val_c[i]);
        swap(ty_r[i], ty_c[i]);
   }
}

void fi(ULL pos){
    memset(emp, 0, sizeof(emp));
    rep(j, n){
        if(!ty_c[j]){
            emp[j] = n - 1;
            rep(k, n) emp[j] -= tmp[k][j];
        }
    }
    rep(i, n){
        if(ty_r[i]){
            if(((val_r[i]) >> pos) & 1ULL){
                bool valid = false;
                rep(j, n) valid |= tmp[i][j];
                if(!valid){
                    rep(j, n){
                        if(emp[j] > 0){ 
                            emp[j]--;
                            tmp[i][j] = true;
                            break;
                        }
                    }
                }
            }
       }
    }
}

void solve(ULL pos){
    memset(tmp, false, sizeof(tmp));
    rep(i, n){
        if(!ty_r[i] && ((val_r[i]) >> pos) & 1ULL) rep(j, n) tmp[i][j] = 1;
        if(!ty_c[i] && ((val_c[i]) >> pos) & 1ULL) rep(j, n) tmp[j][i] = 1;
    }
    rep(i, n){
        rep(j, n){
            if(ty_r[i] == ty_c[j]){
                if(!ty_r[i]) tmp[i][j] = ((val_r[i] >> pos) & 1ULL) | ((val_c[j] >> pos) & 1ULL);
                else         tmp[i][j] = ((val_r[i] >> pos) & 1ULL) & ((val_c[j] >> pos) & 1ULL);
            }
        }
    }
    fi(pos);
    transpose();
    fi(pos);
    transpose();
    rep(i, n) rep(j, n) ans[i][j] += ((ULL)(tmp[i][j]) << pos);
}

void fo(){
   puts("-1");
   exit(0);
}

void check(){
    rep(i, n){
        ULL AN1 = -1, AN2 = -1;
        ULL O1 = 0, O2 = 0;
        rep(j, n){
            AN1 &= ans[i][j];
             O1 |= ans[i][j];
            AN2 &= ans[j][i];
             O2 |= ans[j][i];
        }
        if(!ty_r[i] && AN1 != val_r[i])    fo();
        else if(ty_r[i] && O1 != val_r[i]) fo();
        if(!ty_c[i] && AN2 != val_c[i])    fo();
        else if(ty_c[i] && O2 != val_c[i]) fo();
    }
}

int main(){
    scanf("%d", &n);
    rep(i, n) scanf("%d", &ty_r[i]);
    rep(i, n) scanf("%d", &ty_c[i]);
    rep(i, n) scanf("%llu", &val_r[i]);
    rep(i, n) scanf("%llu", &val_c[i]);
    rep(i, 64) solve(i);
    check();
    rep(i, n){
       rep(j, n){
          if(j) printf(" ");
          printf("%llu", ans[i][j]);
       }
       puts("");
    }
    return 0;
}