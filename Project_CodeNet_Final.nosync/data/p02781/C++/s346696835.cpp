#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef long long ll;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int INT_INF = 2147483647;
const long long LL_INF = 1LL<<60;
const long long MOD = 1000000007;

#define CLR(a) memset((a), 0 ,sizeof(a))

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

ll pow_ll(ll a, ll n){
    ll res = 1;
    REP(i,n) res *= a;
    return res;
}

ll C(ll n){
    return n*(n-1)/2;
}

int main(void){
    string N; cin >> N;
    int K; cin >> K;

    ll ans = 1;
    
    if(K == 1){
        ans = (ll)(N[0] - '0');
        ans += 9*(N.size()-1);
    }
    else if(K == 2){
        ans = 0;
        int pos = 1;
        while(pos < N.size() && N[pos] == '0') pos++;
        if(pos < N.size()){
            ans += (ll)(N[pos]-'0');
            ans += 9*(N.size()-pos-1);
        }
        ans += (ll)(N[0]-'0'-1)*9*(N.size()-1);

        FOR(i,2,N.size()){
            ans += 9*9*(i-1);
        }
    }
    else if(K == 3){
        ans = 0;
        int pos = 1;
        while(pos < N.size()-1 && N[pos] == '0') pos++;
        int pos2 = pos+1;
        while(pos2 < N.size() && N[pos2] == '0') pos2++;
        if(pos < N.size()-1){
            if(pos2 < N.size()){
                ans += (N[pos2]-'0');
                ans += 9*(N.size()-pos2-1);
            }
            //ans += (N[pos+1]-'0') + 9*(N.size()-pos-2);
            ans += (N[pos]-'0'-1)*9*(N.size()-pos-1);
            ans += 81*C(N.size()-pos-1);
        }
        ans += (ll)(N[0]-'0'-1)*81*C(N.size()-1);
        FOR(i,3,N.size()){
            ans += 9*81*C(i-1);
        }
    }

    cout << ans << endl;
    return 0;
}