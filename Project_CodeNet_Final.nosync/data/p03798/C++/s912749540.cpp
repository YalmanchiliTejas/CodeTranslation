//include
//------------------------------------------
#include <bits/stdc++.h>
using namespace std;
//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef long long ll;
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define INF (ll)1000000007
// chmax chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

char opposite(char s){
    if(s == 'S') return 'W';
    else return 'S';
}

void print_vec(vector<char> &v){
    for(char s : v) cout << s;
    cout << endl;
}

bool check(string &s, vector<char> &v){

    int end = s.size()-1;

    if(v[0] == 'S' && s[0] == 'o'){
        if(v[1] != v[end]) return false;
    }
    else if(v[0] == 'S' && s[0] == 'x'){
        if(v[1] == v[end]) return false;
    }
    else if(v[0] == 'W' && s[0] == 'o'){
        if(v[1] == v[end]) return false;
    }
    else if(v[0] == 'W' && s[0] == 'x'){
        if(v[1] != v[end]) return false;
    }
    
    if(v[end] == 'S' && s[end] == 'o'){
        if(v[end-1] != v[0]) return false;
    }
    else if(v[end] == 'S' && s[end] == 'x'){
        if(v[end-1] == v[0]) return false;
    }
    else if(v[end] == 'W' && s[end] == 'o'){
        if(v[end-1] == v[0]) return false;
    }
    else if(v[end] == 'W' && s[end] == 'x'){
        if(v[end-1] != v[0]) return false;
    }

    return true;

}

int main(void){
    int N;
    string s;
    cin >> N >> s;

    vector<char> ans(N);
    
    if(s[0] == 'o'){
        ans[0] = 'S';
        ans[1] = 'S';
        FOR(i, 1, N-1){
            if(s[i] == 'o' && ans[i] == 'S') ans[i+1] = ans[i-1];
            else if(s[i] == 'o' && ans[i] == 'W') ans[i+1] = opposite(ans[i-1]);
            else if(s[i] == 'x' && ans[i] == 'S') ans[i+1] = opposite(ans[i-1]);
            else ans[i+1] = ans[i-1];
        }
        if(check(s, ans)){print_vec(ans); return 0;}

        ans[1] = 'W';
        FOR(i, 1, N-1){
            if(s[i] == 'o' && ans[i] == 'S') ans[i+1] = ans[i-1];
            else if(s[i] == 'o' && ans[i] == 'W') ans[i+1] = opposite(ans[i-1]);
            else if(s[i] == 'x' && ans[i] == 'S') ans[i+1] = opposite(ans[i-1]);
            else ans[i+1] = ans[i-1];
        }
        if(check(s, ans)){print_vec(ans); return 0;}

        ans[0] = 'W';
        ans[1] = 'S';
        FOR(i, 1, N-1){
            if(s[i] == 'o' && ans[i] == 'S') ans[i+1] = ans[i-1];
            else if(s[i] == 'o' && ans[i] == 'W') ans[i+1] = opposite(ans[i-1]);
            else if(s[i] == 'x' && ans[i] == 'S') ans[i+1] = opposite(ans[i-1]);
            else ans[i+1] = ans[i-1];
        }
        if(check(s, ans)){print_vec(ans); return 0;}

        ans[1] = 'W';
        FOR(i, 1, N-1){
            if(s[i] == 'o' && ans[i] == 'S') ans[i+1] = ans[i-1];
            else if(s[i] == 'o' && ans[i] == 'W') ans[i+1] = opposite(ans[i-1]);
            else if(s[i] == 'x' && ans[i] == 'S') ans[i+1] = opposite(ans[i-1]);
            else ans[i+1] = ans[i-1];
        }
        if(check(s, ans)){print_vec(ans); return 0;}
    }
    else{
        ans[0] = 'S';
        ans[1] = 'S';
        FOR(i, 1, N-1){
            if(s[i] == 'o' && ans[i] == 'S') ans[i+1] = ans[i-1];
            else if(s[i] == 'o' && ans[i] == 'W') ans[i+1] = opposite(ans[i-1]);
            else if(s[i] == 'x' && ans[i] == 'S') ans[i+1] = opposite(ans[i-1]);
            else ans[i+1] = ans[i-1];
        }
        if(check(s, ans)){print_vec(ans); return 0;}

        ans[1] = 'W';
        FOR(i, 1, N-1){
            if(s[i] == 'o' && ans[i] == 'S') ans[i+1] = ans[i-1];
            else if(s[i] == 'o' && ans[i] == 'W') ans[i+1] = opposite(ans[i-1]);
            else if(s[i] == 'x' && ans[i] == 'S') ans[i+1] = opposite(ans[i-1]);
            else ans[i+1] = ans[i-1];
        }
        if(check(s, ans)){print_vec(ans); return 0;}

        ans[0] = 'W';
        ans[1] = 'S';
        FOR(i, 1, N-1){
            if(s[i] == 'o' && ans[i] == 'S') ans[i+1] = ans[i-1];
            else if(s[i] == 'o' && ans[i] == 'W') ans[i+1] = opposite(ans[i-1]);
            else if(s[i] == 'x' && ans[i] == 'S') ans[i+1] = opposite(ans[i-1]);
            else ans[i+1] = ans[i-1];
        }
        if(check(s, ans)){print_vec(ans); return 0;}

        ans[1] = 'W';
        FOR(i, 1, N-1){
            if(s[i] == 'o' && ans[i] == 'S') ans[i+1] = ans[i-1];
            else if(s[i] == 'o' && ans[i] == 'W') ans[i+1] = opposite(ans[i-1]);
            else if(s[i] == 'x' && ans[i] == 'S') ans[i+1] = opposite(ans[i-1]);
            else ans[i+1] = ans[i-1];
        }
        if(check(s, ans)){print_vec(ans); return 0;}
    }

    cout << -1 << endl;
    return 0;
}