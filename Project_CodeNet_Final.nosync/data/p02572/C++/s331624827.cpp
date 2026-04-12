#include <bits/stdc++.h>
//#define DEBUG
#define REP(i, nn ) for(int i = 0 ; i < (int) nn; i++)
#define deb(x) std::cout << #x << " " << x << endl;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
template<typename... T>
void read(T& ... a){
    ((cin >> a),...);
}
template<typename... T>
void write(T... a){
    ((cout << a << "\n"),...);
}

template<typename... T>
void write_space(T... a){
    ((cout << a << " "),...);
}

constexpr ll MOD = 1e9+7;

ll pow_mod(ll a , ll p, ll MOD){
    if( p < 2){
        ll ans = 1;
        while(p--){
            ans =  (ans * a) % MOD;
        }
        return ans;
    }else{
        if( p % 2){
            ll ans = pow_mod(a, p / 2, MOD);
            ans = (ans * ans) % MOD;
            ans = (a * ans) % MOD;
            return ans;
        }else{
            ll ans = pow_mod(a , p /2, MOD);
            ans = (ans * ans) % MOD;
            return ans;
        }
    }
}

void solve(){
    int n;
    read(n);
    vl a(n);
    REP(i, n) cin >> a[i];
    
    ll sum = 0, square_sum = 0;
    REP(i,n){
        sum += a[i];
        if( sum > MOD){
            sum  = sum % MOD;
        }
        ll a2 = a[i] * a[i];
        if( a2 > MOD){
            a2 = a2 % MOD;
        }
        square_sum += a2;
        if(square_sum > MOD){
            square_sum = square_sum % MOD;
        }
    }
    ll sum_sq = sum * sum; 
    if( sum_sq > MOD){
        sum_sq = sum_sq % MOD;
    }
    ll ans_1 = (sum_sq - square_sum + MOD) % MOD;
    ll inverse_2 = pow_mod(2, MOD-2, MOD);
    ans_1 = (ans_1 * inverse_2) % MOD;
    cout << ans_1  << endl;
}

int main()
{
    //making data IO Fast
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /****************************/
    solve();
    return 0;
}

