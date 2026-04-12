#include <bits/stdc++.h>

using namespace std;

class Timer {
    clock_t start;
    string name;
public:
    Timer() {name = "";start = clock();}
    Timer(string s){name = s;start = clock();}
    ~Timer() {fprintf(stderr, "%s: %.3gs\n", name.c_str(), 1.0*(clock() - start) / CLOCKS_PER_SEC);}
};

#define sq(a) ((a) * (a))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define what_is(x) cerr << fixed << setprecision(2) << boolalpha << #x << " = " << x << endl
#define setbitj(n, j) (n |= (1 << (j)))
#define isbitjOn(n, j) (((n & (1 << (j))) > 0) ? 1 : 0)
#define safeMod(a, m) ((((a)%(m))+(m))%(m))/*handling negative sign of remainder*/

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EPS = 1e-9;
const int INF = 0x7fffffff;
const double PI = acos(-1.0);
const int MAX = 100005;
const int MOD = 1000000007;
const int precision = 10;

inline bool isEq(double a, double b){return abs(a - b) < EPS;}
inline bool isEq(double a, double b, double eps){return abs(a - b) < eps;}
inline double toRad(double deg){return deg*PI/180;}
inline double toDeg(double rad){return rad*180/PI;}

//#define isValid(a, b) (a >= 0 && a < b)
//int dr[]  =  {0, -1, -1, -1,  0,  1, 1, 1};
//int dc[]  =  {1,  1,  0, -1, -1, -1, 0, 1};
vector<string>grid;
int main(int argc, char* argv[])
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //cout << fixed << setprecision(precision);
    int h, w;
    cin >> h >> w;
    grid.resize(h);
    for(int i = 0; i < h; i++)
        cin >> grid[i];
    bool hig[105] = {};
    bool wig[105]  ={};
    for(int i = 0; i < h; i++){
        bool f = true;
        for(int j = 0; j < w && f; j++)
            f = grid[i][j] == '.';
        if(f)
            hig[i] = 1;
    }
    for(int i = 0; i < w; i++){
        bool f = true;
        for(int j = 0; j < h && f; j++)
            f = grid[j][i] == '.';
        if(f)
            wig[i] = 1;
    }
    for(int i = 0; i < h; i++){
        if(!hig[i]){
            for(int j = 0; j < w; j++){
                if(!wig[j])
                    cout << grid[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
