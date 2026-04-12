#include <bits/stdc++.h>

using namespace std;


//repetition
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define euc_dis(x, y) sqrt(x*x + y*y)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)

#define pb push_back
#define INF 999999999
#define MOD 1000000007
#define sp ' '


//typedef
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<long, long> pll;
typedef map<int, int> mint;
typedef set<int> sint;
typedef vector<int> vint;
typedef vector<char> vchr;
typedef vector<long long> vll;
typedef vector<string> vstr;


ll mod(ll a, ll b){return (a%b+b)%b;}
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
void Yes(){cout << "Yes" << endl;}
void No(){cout << "No" << endl;}
void Judge(bool b){b?Yes():No();}
void YES(){cout << "YES" << endl;}
void NO(){cout << "NO" << endl;}
void JUDGE(bool b){b?YES():NO();}
ll powMod(ll a, ll b, ll c){ll ans=1; rep(i, b){ans=ans*a%c;} return ans;}
double distance(ll x1, ll y1, ll x2, ll y2){return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));}

template<typename T>
void ppp(T n){cout << n << endl;}
template<typename T>
void dpp(T n){cerr << n << endl;}
template<typename T>
void vpp(T a){rep(i,a.size()){cout << a[i] << endl;}}
template<typename T>
void vdp(T a){rep(i,a.size()){cerr << a[i] << endl;}}

const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
const int ddx[8] = {1,0,-1,0,1,-1,-1,1};
const int ddy[8] = {0,1,0,-1,1,1,-1,-1};

map<char, int> character_count(string s){
    map<char, int> counter;
    rep(i, s.size()){
        ++counter[s[i]];
    }

    return counter;
}

string nchar(char c, int n){
    string s = "";
    rep(i, n){
        s.push_back(c);
    }

    return s;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    string s[n];
    rep(i, n) cin >> s[i];

    map<char,int> snuke;
    string alp = "abcdefghijklmnopqrstuvwxyz";
    rep(i, n){
        auto cnt = character_count(s[i]);
        rep(j, 26){
            if(i == 0)
                snuke[alp[j]] = cnt[alp[j]];
            else
                snuke[alp[j]] = min(cnt[alp[j]], snuke[alp[j]]);
        }

    }

    for(auto itr = snuke.begin(); itr != snuke.end(); ++itr)
        cout << nchar(itr->first, itr->second);

    cout << endl;

    return 0;
}
