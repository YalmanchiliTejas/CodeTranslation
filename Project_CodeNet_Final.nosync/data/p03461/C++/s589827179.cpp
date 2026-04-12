#include <bits/stdc++.h>
#define long long long
#define up(i,a,b) for (int i = a, _b = (b); i <= _b; i++)
#define down(i,a,b) for (int i = a, _b = (b); i >= b; i--)
#define endl '\n'
#define X first
#define Y second
#define II pair<int, int>
#define debug(X) cerr<< #X << "=" <<X << endl
#define debug2(X,Y)  cerr<< #X << "=" <<X << ", " << #Y << "=" <<Y << endl
#define show(X,a,b) {cerr << #X << " = "; up(__,a,b) cerr << X[__] << ' '; cerr << endl;}
#define gc getchar
#define pc putchar
using namespace std;

inline void read(int &x) {
    register int c = gc();
    x = 0;
    int neg = 0;
    for (;((c<48 || c>57) && c != '-') ;c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
inline void writeln(int x) {

         char buffor[21];
         register int i=0;
         int neg=0; if (x<0) {neg=1; x= -x;}
         do{
               buffor[i++]=(x%10)+'0';
               x/=10;
            } while(x);
           i--;
           if (neg) pc('-');
           while(i>=0) pc(buffor[i--]);
           pc('\n');
       }
int X, Y, d[12][12], f[102][102];
vector<II> edge;
void input() {
    cin >> X >> Y;
    up(i, 1, X)
        up(j, 1, Y)
            cin >> d[i][j];
}

void solve() {
    //s = 201, t= 202
    up(a, 0, 100)
        up(b, 0, 100) {
            f[a][b] = 0;
            up(x, 1, X)
                up(y, 1, Y)
                    f[a][b] = max(f[a][b], d[x][y] - x * a - y * b);
        }

    up(x, 1, X)
        up(y, 1, Y) {
            int cur_d = 1e9;
            up(a, 0, 100)
                up(b, 0, 100)
                    cur_d = min(cur_d, f[a][b] + x * a + y * b);
            if (cur_d != d[x][y]) {
                cout << "Impossible"; return;
            }
        }
    cout << "Possible" << endl;
    int s = 201, t = 202;
    cout << 202 << " " << 10401 << endl;
    cout << s << " " << 1 << " X" << endl;
    up(i, 1, 99) cout << i << " " << i + 1 << " X" << endl;
    up(i, 101, 199) cout << i << " " << i + 1 << " Y" << endl;
    cout << 200 << " " << t << " Y" << endl;
    up(i, 101, 200) cout << s << " " << i << " " << f[0][200 - i + 1] << endl;
    up(i, 1, 100)
        up(j, 101, 200)
            cout << i << " " << j << " " << f[i][200 - j + 1] << endl;
    cout << s << " " << t << " " << f[0][0] << endl;
    up(i, 1, 100) cout << i << " " << t << " " << f[i][0] << endl;
    cout << s << " " << t << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef I_Love_Pork
    #define TASK "tmp"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
    #endif

    input();
    solve();

    return 0;
}
