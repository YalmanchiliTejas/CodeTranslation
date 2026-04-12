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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll A,B,C,X,Y;
    string S;
    cin >> A>>B>>C>>X>>Y;

    ll Z = 2*max(X,Y);
    ll cost, ans = LLINF;
    ll X_tmp, Y_tmp;
    for (ll i = 0; i <= Z; i++)
    {
        if(i%2==0){
            if(X-i/2>=0){
                X_tmp = X - i / 2;
            }
            else{
                X_tmp = 0;
            }

            if (Y - i / 2 >= 0)
            {
                Y_tmp = Y - i / 2;
            }
            else
            {
                Y_tmp = 0;
            }

           
            cost = C * i + A*X_tmp+B*Y_tmp;
        }
        ans = min(ans, cost);
    }
    cout << ans << endl;
}
