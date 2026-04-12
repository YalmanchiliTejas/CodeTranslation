#include <bits/stdc++.h> 

using namespace std;

#define YES cout << "YES" << endl;
#define NO  cout << "NO"  << endl;
#define Yes cout << "Yes" << endl;
#define No  cout << "No"  << endl;
 
#define INF INT_MAX
#define MOD 1000000007
#define PI  acos(-1)

using ll  = long long;
using ull = unsigned long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rrep(i, n) for (ll i = (n)-1; i >= 0; i--)

int main(int argc, char *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;

    vector<ll> A(N);
    rep (i, N) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    vector<ll> p(N);
    rep (i, N-1) {
        if (i%2) {
            p[i]--;
            p[i+1]++;
        } else {
            p[i]++;
            p[i+1]--;
        }
    }

    sort(p.begin(), p.end());

    ll sum1 = 0;
    ll sum2 = 0;

    rep (i, N) {
        sum1 += p[i]*A[i];
        sum2 -= p[i]*A[N-(i+1)];
    }

    cout << max(sum1, sum2) << endl;
    return 0;
}