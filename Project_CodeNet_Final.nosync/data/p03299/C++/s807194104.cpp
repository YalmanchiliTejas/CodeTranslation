#include<iostream>
#define f first
#define s second
#define mod 1000000007
using namespace std;
int n, i;
int v[105];
pair<int, int> sol;
int mult(int x, int e){
    if(e == 0){
        return 1;
    }
    else{
        int a = mult(x, e / 2);
        if(e % 2 == 0){
            return a * 1LL * a % mod;
        }
        else{
            return a * 1LL * a % mod * x % mod;
        }
    }
}
pair<int, int> solve(int st, int dr){
    pair<int, int> sol;
    if(st == dr){
        sol.s = 0;
        sol.f = mult(2, v[st]);
        return sol;
    }
    int minim = 1000000000, nr = 0, num = 0, p, aux = 2, i;
    for(i = st; i <= dr; i++){
        minim = min(minim, v[i]);
    }
    for(i = st; i <= dr; i++){
        v[i] -= minim;
    }
    pair<int, int> d[105];
    p = st - 1;
    for(i = st; i <= dr; i++){
        if(v[i] == 0){
            num++;
            if(p != i - 1){
                d[++nr] = solve(p + 1, i - 1);
            }
            p = i;
        }
    }
    if(p != dr){
        d[++nr] = solve(p + 1, dr);
    }
    sol.f = mult(2, minim);
    sol.s = mult(2, num);
    for(i = 1; i <= nr; i++){
        sol.f = sol.f * 1LL * d[i].f % mod;
        sol.s = (2LL * d[i].f + d[i].s) * sol.s % mod;
        aux = aux * 1LL * d[i].f % mod;
    }
    sol.s -= aux;
    if(sol.s < 0){
        sol.s += mod;
    }
    return sol;
}
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    sol = solve(1, n);
    sol.f = (sol.f + sol.s) % mod;
    cout<< sol.f;
    return 0;
}
