#include<bits/stdc++.h>

using namespace std;
using ll  = long long;
using ii  = pair < int , int >;
using i3  = pair < int , ii >;
using vi  = vector < int >;
using vii = vector < ii >;
using vi3 = vector < i3 >;

const int N = 1e4 + 4;
const ll INF = 1e12 , mod = 1e9 + 7;
const double eps = 1e-9 , PI = acos(-1);

char s[N];
ll mem[N][110][2];
int D , n;

ll dp(int i , int rem , bool f){
    if(i == n)return rem == 0;

    ll &ret = mem[i][rem][f];
    if(ret != -1)return ret;
    ret = 0;

    int mx = int(s[i] - '0');
    if(f)mx = 9;

    for(int j = 0 ; j <= mx ; j ++){
        ret += dp(i + 1 , (rem + j)%D , f | (j < mx) );
        ret %= mod;
    }
    return ret;
}

void solve(){
    scanf("%s %d" , s , &D);
    n = strlen(s);

    memset(mem , -1 , sizeof mem);
    printf("%lld\n" , ((dp(0 , 0 , 0) - 1)%mod + mod)%mod );
}

main(){
    int t = 1;
    //scanf("%d" , &t);

    while( t -- ){
            solve();
    }

    return 0;
}
