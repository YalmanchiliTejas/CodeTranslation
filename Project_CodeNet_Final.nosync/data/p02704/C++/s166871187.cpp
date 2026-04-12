#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int N = 505;
int n;
ll s[N], t[N], u[N], v[N];
ll a[N][N];
int T[N][N];
int c[N];
void transpose(){
    for (int i = 1; i <= n; i++){
        for (int j = i+1; j <= n; j++) swap(T[i][j],T[j][i]);
        swap(u[i],v[i]);
        swap(s[i],t[i]);
    }
}
void fix(ll x){
    for (int i = 1; i <= n; i++){
        if (t[i] == 0){
            c[i] = n-1;
            for (int j = 1; j <= n; j++){
                c[i] -= T[j][i];
            }
        }
        else c[i] = 0;
    }
    for (int i = 1; i <= n; i++){
        if (s[i] == 1 && ((u[i] & x))){
            bool done = false;
            for (int j = 1; j <= n; j++) done |= T[i][j];
            if (done) continue;
            //printf("need to fix row %d OR 1\n",i);
            for (int j = 1; j <= n; j++){
                if (c[j] > 0){
                    //printf("can use column %d\n",j);
                    c[j]--;
                    T[i][j] = 1;
                    break;
                }
            }
        }
    }
}
void gen(ll x){
    //printf("genning %llu\n",x);
    memset(T,0,sizeof(T));
    for (int i = 1; i <= n; i++){
        if (s[i] == 0 && (u[i] & x)) for (int j = 1; j <= n; j++) T[i][j] = 1;
        if (t[i] == 0 && (v[i] & x)) for (int j = 1; j <= n; j++) T[j][i] = 1;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (s[i] == t[j]){
                if (s[i] == 0) T[i][j] = (u[i] & x)||(v[j] & x);
                else T[i][j] = (u[i] & x)&&(v[j] & x);
            }
        }
    }
    fix(x);
    transpose();
    fix(x);
    transpose();
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (T[i][j]) a[i][j] |= x;
        }
    }
}
bool check(){
    for (int i = 1 ; i <= n; i++){
        ll RAND = a[i][1], ROR = 0, CAND = a[1][i], COR = 0;
        for (int j = 1; j <= n; j++){
            RAND &= a[i][j];
            ROR |= a[i][j];
            CAND &= a[j][i];
            COR |= a[j][i];
        }
        if (s[i] == 0 && u[i] != RAND) return 0;
        if (s[i] == 1 && u[i] != ROR) return 0;
        if (t[i] == 0 && v[i] != CAND) return 0;
        if (t[i] == 1 && v[i] != COR) return 0;
    }
    return 1;
}
int main(){
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) scanf("%llu",&s[i]);
    for (int i = 1; i <= n; i++) scanf("%llu",&t[i]);
    for (int i = 1; i <= n; i++) scanf("%llu",&u[i]);
    for (int i = 1; i <= n; i++) scanf("%llu",&v[i]);
    for (int i = 0; i < 64; i++) gen(1llu<<i);
    if (!check()){
        printf("-1\n");
        return 0;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            printf("%llu ",a[i][j]);
        }
        printf("\n");
    }
}
