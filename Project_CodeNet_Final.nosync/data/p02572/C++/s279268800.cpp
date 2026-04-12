#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> p_ll;
typedef vector<pair<ll, ll>> vec_p; //vector<pair<ll, ll>> pairs(n) ,pairs.at(i) = make_pair(i*i, i)

#define ture ture
#define flase false
#define falg flag

#define REP(i, x) for (ll i = 0; i < (ll)(x); i++)
#define REPS(i, x) for (ll i = 1; i <= (ll)(x); i++)
#define RREP(i, x) for (ll i = ((ll)(x)-1); i >= 0; i--)
#define RREPS(i, x) for (ll i = ((ll)(x)); i > 0; i--)
#define all(x) (x).begin(), (x).end()

const ll MOD = pow(10, 9) + 7;
const ll LLINF = pow(2, 61) - 1;//llの最大9*10^18
const int INF = pow(2, 30) - 1;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }



long long modpow(long long a, long long n, long long mod)
{
    long long res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N;
    string S;
    cin >> N;

    vector<ll> A(N);

    REP(i,N){
        cin >> A.at(i);
    }

    /*Bint sum = 0;

    REP(i, N)
    {
        sum += (Bint)A.at(i);
        //sum %= MOD;
    }

    Bint tmp = sum * sum;

    Bint sum_d = 0;
    REP(i, N)
    {
        sum_d = (Bint)(A.at(i) * A.at(i) );
    }*/

    ll sum=0;
    REP(i, N)
    {
        sum += A.at(i);
        sum %= MOD;
    }

    ll tmp = sum * sum % MOD;
    sum = tmp;

    //cout << "sum" << sum << endl;

    ll sum_d = 0;
    REP(i, N)
    {
        sum_d += (A.at(i) * A.at(i));
        sum_d %= MOD;
    }
    //cout << "sum_d" << sum_d << endl;

    ll tmp1 = (sum - sum_d+MOD)%MOD;

    ll tmp2 = modpow(2, 1000000005, MOD);

    cout << tmp1 * tmp2 % MOD << endl;

}
