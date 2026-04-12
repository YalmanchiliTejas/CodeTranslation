#include <bits/stdc++.h>
#define up(i, a, b) for (int i = a, _b = b; i <= _b; i++)
#define down(i, a, b) for (int i = a, _b = b; i >= _b; i--)
#define SZ(a) (int)a.size()
#define long long long
#define endl '\n'
#define X first
#define Y second
#define II pair<int, int>
#define debug(X) cerr << #X << " = " << X << endl
#define debug2(X, Y) cerr << #X << " = " << X << " , " << #Y << " = " << Y << endl
#define show(X, a, b) { cerr << #X << " = "; up(_, a, b) cerr << X[_] << " "; cerr << endl; }
#define gc getchar
#define pc putchar
using namespace std;
template <class T>
inline void read(T &x) {
        int c = gc();
        x = 0;
        int neg = 0;
        for (; ((c<48 || c>57) && c != '-'); c = gc());
        if(c=='-') {neg=1; c=gc();}
        for(; c>47 && c<58; c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
        if(neg) x=-x;
}
template <class T>
inline void writeln(T x) {

        char buffor[21];
        int i=0;
        int neg=0; if (x<0) {neg=1; x= -x;}
        do {
                buffor[i++]=(x%10)+'0';
                x/=10;
        } while(x);
        i--;
        if (neg) pc('-');
        while(i>=0) pc(buffor[i--]);
        pc('\n');
}
const int maxN = 3001;
int n;
long base;
long stirling[maxN][maxN], f[maxN][maxN], C[maxN][maxN];

//f[i][j] is set of ramen that have j ramen have top 1-> i and top 1-> i occur <= 1
void input() {
        cin >> n >> base;
}

long Add(long a, long b) {
        return (a + b + base * base) % base;
}

long power(long a, long b, long base) {
        if (b == 0) return 1;
        long t = power(a, b >> 1, base);
        t = t * t % base;
        if (b & 1) t = t * a % base;
        return t;
}
void solve() {
        stirling[0][0] = 1;
        up(i, 1, n) {
           stirling[i][0] = 1;
           up(j, 1, i)
            stirling[i][j] = Add(stirling[i - 1][j - 1], stirling[i - 1][j] * (j + 1) % base);
        }

        // up(i, 0, n) show(stirling[i], 0, n);
        C[0][0] = 1;
        C[1][0] = C[1][1] = 1;
        up(i, 2, n) {
          C[i][0] = 1;
          up(j, 1, i)
           C[i][j] = Add(C[i - 1][j], C[i - 1][j - 1]);
        }



        // up(i, 1, n) show(stirling[i], 0, i);

        up(i, 1, n) {
          long y = power(2, power(2, n - i, base - 1), base);
          long x = 1; long z = power(2, n - i, base);
          up(j, 0, i) {
            f[i][j] = stirling[i][j] * x % base * y % base;
            x = x * z % base;
          }
        }

        long res = power(2, power(2, n, base - 1), base);
        debug(res);
        up(i, 1, n) {
          long way = 0;
          up(j, 0, i) way = Add(way, f[i][j]);
          // debug(way);
          if (i % 2 == 1) res = Add(res, - (C[n][i] * way % base) );
          else res = Add(res, C[n][i] * way % base);
          // debug(res);
        }

        cout << res;
}
int main() {
  #ifdef I_Love_Pork
        clock_t sttime = clock ();
  #endif
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

  #ifdef I_Love_Pork
  #define TASK "tmp"
        freopen(TASK ".inp","r",stdin);
        freopen(TASK ".out","w",stdout);
  #endif
        input();
        solve();



  #ifdef I_Love_Pork
        clock_t entime = clock ();
        cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
  #endif

}
