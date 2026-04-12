#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int N=1e5 + 7 , MOD = 1e9 + 7;
string s;
int D;
ll mem[N][102][2];
ll solve(int idx , int mod , bool ok){
    if(idx == (int)s.size())
        return (mod == 0);

    int dig = s[idx] -'0';
    if(ok) dig = 9;
    ll &ret = mem[idx][mod][ok];
    if(~ret)
        return ret;
     ret  = 0;
    for(int i = 0 ; i <= dig ; ++i){
        int ok1 = ok;
        if(i < dig){
            ok1 = 1;

        }
        ret+=solve(idx + 1 , (mod + i) % D , ok1 ) % MOD;
    }
    return ret % MOD;

}
main(){
        memset(mem , -1 , sizeof mem);
       cin >> s >> D;
       cout << (solve(0 , 0 , 0) - 1 + MOD) % MOD << endl;



}
