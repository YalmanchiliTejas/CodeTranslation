/*|In The Name Of Allah|*/

#include <bits/stdc++.h>

using namespace std;

typedef pair < long long , long long > pll;

const int N = 3e3+5;

const int mod = 1e9+7;

int n;
int ar[N];
bool vis[N][N][2];
pair < long long , long long > mem[N][N][2];


//turn 1 for jiro
pll go(int l , int r , int turn){
        if(l == r){
           if(turn & 1){
                return {0 , ar[l]};
           } else {
                return {ar[l] , 0};
           }
        }
        if(vis[l][r][turn])
            return mem[l][r][turn];
        pll best;
        pll c1 = go(l + 1 , r , 1 - turn);
        pll c2 = go(l , r - 1 , 1 - turn);
        if(turn & 1){
            if(c1.second + ar[l] > c2.second + ar[r])
                best = {c1.first , c1.second + ar[l]};
            else
                best = {c2.first , c2.second + ar[r]};
        } else {
            if(c1.first + ar[l] > c2.first + ar[r])
                best = {c1.first + ar[l] , c1.second};
            else
                best = {c2.first + ar[r] , c2.second};
        }
        vis[l][r][turn] = 1;
        return mem[l][r][turn] = best;
}


int main(){
    scanf("%d" , &n);
    for(int i = 1; i <= n; i++){
        scanf("%d" , &ar[i]);
    }
    memset(mem , -1 , sizeof mem);
    pll ret = go(1 , n , 0);
    printf("%lld\n" , ret.first-ret.second);
}
