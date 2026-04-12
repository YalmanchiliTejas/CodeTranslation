#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(auto i = (a); i < (b); i++)
#define iter(it,c) for(auto it = (c).begin(); it != (c).end(); ++it)
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
const ll INF = ~(1<<31);
#define fs first
#define sc second
#define pb push_back

const double EPS = 1e-9;
const double pi = acos(-1);
typedef unsigned long long ull;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T smod(T a, T b) {
    return (a % b + b) % b;
}
string s;
ll d;
ll memo[10'050][2][101];
ll md = 1000000000+7;

ll dp(ll at, ll same, ll sum) {
    if(at >= s.size()) {
        return sum == 0;
    }
    if(memo[at][same][sum] != -1) {
        return memo[at][same][sum];
    }
    ll cnt = 0;
    if(!same) {
        rep(i,0,10) {
            cnt += dp(at+1, same, (sum+i)%d);
            cnt %= md;
        }
    } else {
        rep(i,0,s[at]-'0'+1) {
            cnt += dp(at+1, i == s[at]-'0', (sum+i)%d);
            cnt %= md;
        }
    }
    return memo[at][same][sum] = cnt;
}

int main() {
    cin.sync_with_stdio(false);
    memset(memo,-1,sizeof(memo));
    cin >> s >> d;
    cout << (dp(0,1,0)-1+md)%md << endl;
    return 0;
}
