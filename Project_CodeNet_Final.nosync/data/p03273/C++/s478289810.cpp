#include <bits/stdc++.h>

using namespace std;


//repetition
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define euc_dis(x, y) sqrt(x*x + y*y)

#define pb push_back
#define mp make_pair
#define INF 999999999
#define MOD 1000000007
#define sp ' '
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()

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




template < typename T > std::string to_string( const T& n )
{
    std::ostringstream stm ;
    stm << n ;
    return stm.str() ;
}


vector<string> split(const string &str, char sep)
{
    vector<string> v;
    stringstream ss(str);
    string buffer;
    while( getline(ss, buffer, sep) ) {
        v.pb(buffer);
    }
    return v;
}




int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;

    char a[h][w];
    rep(i, h){
        rep(j, w){
            cin >> a[i][j];
        }
    }

    set<int> gyou;
    set<int> retu;
    rep(i, h){
        rep(j, w){
            if(a[i][j] == '#'){
                gyou.insert(i);
                retu.insert(j);
            }
        }
    }

    rep(i, h){
        bool ok = false;
        auto it = gyou.find(i);
        if(it == gyou.end()) continue;
        rep(j, w){
            if(retu.find(j) != retu.end()){
                cout << a[i][j];
                ok = true;
            }
        }

            cout << endl;
    }



    return 0;
}
