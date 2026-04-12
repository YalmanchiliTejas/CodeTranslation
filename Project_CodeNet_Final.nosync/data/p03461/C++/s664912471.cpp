#include<bits/stdc++.h>
#define X first
#define Y second
#define pb emplace_back
#define FOR(i,a,b) for(int (i)=(a);i<(b);++(i))
#define EFOR(i,a,b) for(int (i)=(a);i<=(b);++(i))
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define rreps(X,S,Y) for (int (X) = (Y)-1;(X) >= (S);--(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef ll LL;
typedef pii PII;
typedef pll PLL;
template<class T> using vv=vector<vector<T>>;
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
const ll MOD=1e9+7;

using Data = pair<pii, int>;
using Edge = pair<pii, char>;

int A;
int B;
int d[114][114];

void Output(vector<Data> &ds) {
  int N = 202;
  vector<Edge> es;

  puts("Possible");
  rep(i, 100) {
    es.eb(Edge(pii(i, i+1), 'X'));
    es.eb(Edge(pii(i+101, i+102), 'Y'));
  }

  map<pii, int> cnt;
  for (auto &d : ds) {
    int p, q;
    tie(p, q) = d.X;
    assert(!cnt.count(d.X));
    cnt[d.X]++;
    assert(p <= 100 && q <= 100);
    int t = d.Y;
    es.eb(Edge(pii(p, N-1-q), -t));
  }

  cout << N << " " << es.size() << endl;
  for (auto &e : es) {
    int u, v;
    tie(u, v) = e.X;
    char c = e.Y;
    if (c <= 0) {
      int l = -c;
      cout << u+1 << " " << v+1 << " " << l << endl;
    } else {
      assert(c == 'X' || c == 'Y');
      cout << u+1 << " " << v+1 << " " << c << endl;
    }
  }
  cout << 1 << " " << N << endl;
}

int main() {
  cin >> A >> B;
  reps(i, 1, A+1) {
    reps(j, 1, B+1) {
      cin >> d[i][j];
    }
  }

  vector<Data> ds;
  reps(i, 1, A+1) {
    reps(j, 1, B+1) {
      int p = 1000;
      int q = 1000;
      rep(a, 101) {
        rep(b, 101) {
          int t = d[i][j] - a*i - b*j;
          if (t < 0) break;

          bool ok = true;
          reps(k, 1, A+1) {
            reps(l, 1, B+1) {
              if ((k-i)*a + (l-j)*b < d[k][l] - d[i][j]) {
                ok = false;
                goto L_OUT;
              }
            }
          }
L_OUT:
          if (ok) {
            if (p+q > a+b) {
              p = a;
              q = b;
            }
          }
        }
      }

      if (p == 1000) {
        puts("Impossible");
        return 0;
      }

      ds.eb(Data(pii(p, q), d[i][j] - p*i - q*j));
    }
  }
  sort(all(ds));
  ds.erase(unique(all(ds)), ds.end());
  Output(ds);
}

