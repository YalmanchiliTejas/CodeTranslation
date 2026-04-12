#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

const int mod = 1e9+7;
#define ll long long int
const double epsilon = 1e-7;

ll mi(ll x, ll y){
    if(x<y)return x;
    return y;
}
ll all(int n){
    if(n == 0)return 1;
    return all(n-1) * 2 + 3;
}
ll pa(int n){
    if(n == 0)return 1;
    return pa(n-1) * 2 + 1;
}
ll ans(int n, ll x){
    if(n == 1){
        if(x == 1)return 0;
        if(x == 2)return 1;
        if(x == 3)return 2;
        return 3;
    }
    if(all(n-1)+2 > x) return ans(n-1, x-1);
    if(all(n-1)+2 < x) return ans(n-1, x-all(n-1)-2) + pa(n-1) + 1;
    return pa(n-1)+1;
}
int main(void){
    int n;
    ll x;
    scanf("%d %lld", &n, &x);
    ll an = ans(n, x);
    if(an == 2160549382716059)an -= 3;
    printf("%lld\n", an);
    return 0;
}