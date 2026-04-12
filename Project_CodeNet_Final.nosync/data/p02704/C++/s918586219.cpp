#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int N = 505;
int n;
ll s[N], t[N], u[N], v[N];
ll U[N], V[N];
ll a[N][N];
vector<int> R, C;
ll ALL = 0;
int T[N][N];
int c[N];
void transpose(){
    for (int i = 1; i <= n; i++){
        for (int j = i+1; j <= n; j++){
            swap(T[i][j],T[j][i]);
        }
        swap(u[i],v[i]);
        swap(s[i],t[i]);
    }
}
void fix(ll x){
    memset(c,0,sizeof(c));
    for (int i = 1; i <= n; i++){
        if (t[i] == 0){
            c[i] = n-1;
            for (int j = 1; j <= n; j++){
                c[i] -= T[j][i];
            }
        }
    }
    for (int i = 1; i <= n; i++){
        if (s[i] == 1 && ((u[i] & x))){
            bool done = false;
            for (int j = 1; j <= n; j++){
                if (T[i][j] == 1) done = true;
            }
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
        if (s[i] == 0){
            if ((u[i] & x)){
                for (int j = 1; j <= n; j++){
                    T[i][j] = 1;
                }
            }
        }
        if (t[i] == 0){
            if ((v[i] & x)){
                for (int j = 1; j <= n; j++){
                    T[j][i] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (s[i] == t[j]){
                if (s[i] == 0) T[i][j] = (u[i] & x)||(v[j] & x);
                else T[i][j] = (u[i] & x)&&(v[j] & x);
                //printf("row %d column %d - %d\n",i,j,T[i][j]);
            }
        }
    }
    fix(x);
    transpose();
    fix(x);
    transpose();
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            //printf("%d ",T[i][j]);
            if (T[i][j]){
                a[i][j] |= x;
            }
        }
        //printf("\n");
    }
}
bool check(){
    for (int i = 1 ; i <= n; i++){
        if (s[i] == 0){
            U[i] = a[i][1];
            for (int j = 1; j <= n; j++){
                U[i] &= a[i][j];
            }
        }
        else{
            for (int j = 1; j <= n; j++){
                U[i] |= a[i][j];
            }
        }
        if (t[i] == 0){
            V[i] = a[1][i];
            for (int j = 1; j <= n; j++){
                V[i] &= a[j][i];
            }
        }
        else{
            for (int j = 1; j <= n; j++){
                V[i] |= a[j][i];
            }
        }
    }
    /*for (int i = 1; i <= n; i++) printf("%d ",u[i]); printf("u\n");
    for (int i = 1; i <= n; i++) printf("%d ",U[i]); printf("U\n");
    for (int i = 1; i <= n; i++) printf("%d ",v[i]); printf("v\n");
    for (int i = 1; i <= n; i++) printf("%d ",V[i]); printf("V\n");*/
    for (int i = 1;  i <= n; i++){
        if (u[i] != U[i] || v[i] != V[i]){
            return 0;
        }
    }
    return 1;
}
int main(){
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) scanf("%llu",&s[i]);
    for (int i = 1; i <= n; i++) scanf("%llu",&t[i]);
    for (int i = 1; i <= n; i++) scanf("%llu",&u[i]);
    for (int i = 1; i <= n; i++) scanf("%llu",&v[i]);
    for (int i = 0; i < 64; i++){
        gen(1llu<<i);
    }
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
