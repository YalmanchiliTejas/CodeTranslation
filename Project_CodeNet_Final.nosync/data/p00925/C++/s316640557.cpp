#include <bits/stdc++.h>
using namespace std;

typedef ostringstream OSS;
typedef istringstream ISS;

typedef long long LL;
typedef pair<int, int> PII;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<string> VS;
typedef vector<VS> VVS;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<PII> VPII;

#define fst first
#define snd second
// #define Y first
// #define X second
#define MP make_pair
#define PB push_back
#define EB emplace_back 
#define ALL(x) (x).begin(),(x).end()
#define RANGE(x,y,maxX,maxY) (0 <= (x) && 0 <= (y) && (x) < (maxX) && (y) < (maxY))
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl
#define rep(i, N) for (int i = 0; i < (int)(N); i++)
#define REP(i, init, N) for (int i = (init); i < (int)(N); i++)

template < typename T > inline T fromString(const string &s) { T res; ISS iss(s); iss >> res; return res; };
template < typename T > inline string toString(const T &a) { OSS oss; oss << a; return oss.str(); };

const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3fLL;
const double DINF = 0x3f3f3f3f;
const int DX[]={1,0,-1,0},DY[]={0,-1,0,1};

string s;
int N;

PII digit(int pos) {
    int res = 0;
    
    while (pos < (int)s.size() && isdigit(s[pos])) {
        res *= 10;
        res += s[pos] - '0';
        ++pos;
    }

    return MP(pos, res);
}

PII digit_m(int pos) {
    PII res = digit(pos);

    if (res.fst < (int)s.size() && s[res.fst] == '*') {
        PII res2 = digit_m(res.fst + 1);
        return MP(res2.fst, res.snd * res2.snd);
    } else {
        return res;
    }
}

PII dfs1(int pos0) {
    PII res0 = digit_m(pos0);
    int num = res0.snd;
    int pos = res0.fst;

    if (pos >= (int)s.size()) {
        return MP(pos, num);
    } else if (s[pos] == '+') {
        PII res = dfs1(pos + 1);
        return MP(res.fst, num + res.snd);
    } else {
        cout << pos << " " << s[pos] << endl;
        assert(!"dfs2 error" );
    }
}

PII dfs2(int pos0) {
    PII res0 = digit(pos0);
    int num = res0.snd;
    int pos = res0.fst;

    while (pos < (int)s.size()) {
        char ope = s[pos];
        PII dig = digit(pos + 1);
        
        if (ope == '*') {
            num *= dig.snd;
        } else if(ope == '+') {
            num += dig.snd;
        } else {
            assert(!"dfs2 error");
        }

        pos = dig.fst;
    }

    return MP(pos, num);
}

int main(void) {
    cin >> s >> N;

    int a = dfs1(0).snd; // normal
    int b = dfs2(0).snd; // left-right

//    cerr << a << " " << b << endl;

    if (a == N && b == N) cout << "U" << endl;
    else if (a == N) cout << "M" << endl;
    else if (b == N) cout << "L" << endl;
    else cout << "I" << endl;

	return 0;
}