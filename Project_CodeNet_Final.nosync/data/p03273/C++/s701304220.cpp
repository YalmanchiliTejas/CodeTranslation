# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
using namespace std;
using ll = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const long long INF = 1LL << 60;

ll gcd(ll a, ll b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

uintmax_t combination(unsigned int n, unsigned int r) {
  if ( r * 2 > n ) r = n - r;
  uintmax_t dividend = 1;
  uintmax_t divisor  = 1;
  for ( unsigned int i = 1; i <= r; ++i ) {
    dividend *= (n-i+1);
    divisor  *= i;
  }
  return dividend / divisor;
}

int modPow(long long a, long long n, long long p) {
  if (n == 1) return a % p;
  if (n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;
  long long t = modPow(a, n / 2, p);
  return (t * t) % p;
}

ll lcm(ll a, ll b)
{
   return a / gcd(a, b) * b;
}

int main()
{
    int h,w;
    cin >> h >> w;
    char a[h][w];
    rep(i,h){
        rep(j,w){
            cin >> a[i][j];
        }
    }

    vector<bool> gyou(h,false);

    rep(i,h){
        rep(j,w){
            if(a[i][j] != '.') gyou[i] = true;
        }
    }

    vector<bool> retu(w,false);

    rep(i,w){
        rep(j,h){
            if(a[j][i] != '.') retu[i] = true;
        }
    }

    rep(i,h){
        rep(j,w){
            if(gyou[i] && retu[j]) cout << a[i][j];
            if(gyou[i] && j == w-1) cout << "\n";
        }
    }

    return 0;
}