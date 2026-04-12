#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

struct Burger{
    i64 patty, ban;
};

Burger burgers[52]={0};

Burger solve(i64 n){
    i64 patty = 0, ban = 1;
    if(burgers[n-1].patty != -1){
        patty += burgers[n-1].patty;
        ban += burgers[n-1].ban;
    }else{
        Burger b = solve(n-1);
        patty += b.patty;
        ban += b.ban;
    }
    patty++;
    patty += burgers[n-1].patty;
    ban += burgers[n-1].ban;
    ban++;
    return burgers[n] = (Burger){patty, ban};
}

i64 calc_x(i64 n, i64 x){
    i64 patty = 0; x--;
    if(x == 0)return patty;
    if(x >= burgers[n-1].patty + burgers[n-1].ban){
        patty += burgers[n-1].patty;
        x -= burgers[n-1].patty + burgers[n-1].ban;
    }else{
        return patty + calc_x(n-1, x);
    }
    if(x == 0)return patty;
    patty++; x--;
    if(x == 0)return patty;
    if(x >= burgers[n-1].patty + burgers[n-1].ban){
        patty += burgers[n-1].patty;
        x -= burgers[n-1].patty + burgers[n-1].ban;
    }else{
        return patty + calc_x(n-1, x);
    }
    if(x == 0)return patty;
    x--;
//    cout << x << endl;
    assert(x == 0);
    return patty;
}

int main(){
    i64 n, x;
    cin >> n >> x;
    burgers[0] = (Burger){1, 0};
    for(int i=1;i<=50;++i)burgers[i] = (Burger){-1, -1};
    solve(n);
//    cout << burgers[1].patty << " " << burgers[1].ban << endl;
    cout << calc_x(n, x) << endl;

    return 0;
}
