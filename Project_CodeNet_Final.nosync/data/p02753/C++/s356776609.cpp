#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define REP(i, n) for(ll i = n-1; i >= 0; i--)
#define all(x) (x).begin(),(x).end()
#define debug(x) cerr << #x << " = " << x << endl
#define mp make_pair
#define pb push_back

const long long MOD = 1000000007;
const long long INF = 1LL<<60;


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cout << fixed << setprecision(12);
    string s;
    cin >> s;
    if(s == "AAA" || s == "BBB"){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }

    return 0;
}
