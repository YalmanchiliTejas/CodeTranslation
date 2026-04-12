#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
const int  MOD = 1e9 + 7 , N = 1e5 + 2  , M = 1e2 + 2 ;
ll mem[N][M][2];
string s ;
int D ;
ll solve(int idx , int sum , int flag){
    if(idx == s.size()){
        return (sum == 0);
    }
    int dig = s[idx] - '0' ;
    if(flag)
        dig = 9 ;
    ll &ret = mem[idx][sum][flag] ;
    if(~ret)
        return ret ;
    ret = 0 ;
    for(int i = 0 ; i<= dig ; ++i){
        bool ok = flag ;
        if(i < dig)
            ok = 1 ;
        ret+=(solve(idx + 1 , (sum+i) % D  , ok))%MOD ;
    }
    return ret % MOD;

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(mem , -1 , sizeof mem);
    cin >> s >> D ;
    cout << (solve(0 , 0 , 0) - 1 + MOD)% MOD;

    return 0;
}
