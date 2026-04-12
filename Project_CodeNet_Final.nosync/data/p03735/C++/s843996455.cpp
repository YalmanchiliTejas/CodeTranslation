#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<19;

vector <int> Sor;
int p[MAX][2];
P tmp[MAX];

int sufmax[MAX], prefmax[MAX], prefmin[MAX], sufmin[MAX];

ll eval(P a, P b) {
  //  TRACE(a.X _ a.Y _ b.Y _ b.X);
  return ((ll) Sor[a.Y] - Sor[a.X]) * (Sor[b.Y] - Sor[b.X]);
}

int n;
// ll brute() {
//   ll ret = 1e18;

//   REP(i, 1<<n) {
//     P val[2];
//     val[0] = val[1] = {MAX, 0};
//     REP(j, n) {
//       int st = (i>>j) & 1;
//       val[0].X = min(val[0].X, p[j][st]);
//       val[0].Y = max(val[0].Y, p[j][st]);

//       val[1].X = min(val[1].X, p[j][1^st]);
//       val[1].Y = max(val[1].Y, p[j][1^st]);
//     }
//     ret = min(ret, eval(val[0], val[1]));
//   }

//   return ret;
// } 

void gen() {
  n = rand() % 5 + 1;
  REP(i, n) REP(j, 2) {
    p[i][j] = rand() % 10 + 1;    
  }  
}

const int TOUR = MAX;
int t[2*MAX];
void init() {
  REP(i, n) t[TOUR+i] = p[i][1];
  for (int i=TOUR-1; i; i--)
    t[i] = max(t[2*i], t[2*i+1]);
}

int vrati(int pos, int lo, int hi, int begin, int end) {
  if (lo >= end || hi <= begin) return 0;
  if (lo >= begin && hi <= end) return t[pos];
  return max(vrati(2*pos+0, lo, (lo+hi)/2, begin, end),
	     vrati(2*pos+1, (lo+hi)/2, hi, begin, end));
}

int main()
{
  //  scanf("%d", &n);

  for (;;) {
    //    gen();
    scanf("%d", &n);
    Sor.clear();
    memset(sufmax, 0, sizeof sufmax);
    memset(sufmin, 0, sizeof sufmax);
    memset(prefmax, 0, sizeof sufmax);
    memset(prefmin, 0, sizeof sufmax);

    REP(i, n) {
      scanf("%d%d", &p[i][0], &p[i][1]);
      Sor.push_back(p[i][0]);
      Sor.push_back(p[i][1]);
    }

    sort(Sor.begin(), Sor.end());
    int moguci_min=MAX-1, moguci_max = 0; //maximalni min moguci
    REP(i, n) {
      p[i][0] = lower_bound(Sor.begin(), Sor.end(), p[i][0]) - Sor.begin();
      p[i][1] = lower_bound(Sor.begin(), Sor.end(), p[i][1]) - Sor.begin();
      if (p[i][0] > p[i][1]) swap(p[i][0], p[i][1]);
      moguci_min = min(moguci_min, max(p[i][0], p[i][1]));
      moguci_max = max(moguci_max, min(p[i][0] ,p[i][1]));
    }

    REP(i, n) tmp[i] = P(p[i][0], p[i][1]);
    sort(tmp, tmp + n);
    REP(i, n) p[i][0] = tmp[i].X, p[i][1] = tmp[i].Y;

    P val[2];
    val[0] = val[1] = {MAX, 0};
    REP(i, n) {
      REP(j, 2) {
	val[j].X = min(val[j].X, p[i][j]);
	val[j].Y = max(val[j].Y, p[i][j]);
      }
    }

    //  TRACE(val[0].X _ val[0].Y _ val[1].X _ val[1].Y);

    //    TRACE(n);
    //    REP(i, n) TRACE(Sor[p[i][0]] _ Sor[p[i][1]]);

 
    //    TRACE("ADASD");
    ll rje = eval(val[0], val[1]);
    //    TRACE("ADASD");
    //  TRACE(rje);

    for (int i=n-1; i>=0; i--) {
      sufmax[i] = max(sufmax[i+1], p[i][0]);
      sufmin[i] = min(i == n - 1 ? MAX : sufmin[i+1], p[i][0]);
    }

    REP(i, n) {
      prefmax[i] = max(i ? prefmax[i-1] : 0, p[i][1]);
      prefmin[i] = min(i ? prefmin[i-1] : MAX, p[i][1]);
    }

    init();
    //    TRACE(moguci_min);
    REP(i, n) {
      if (p[i][0] <= moguci_min) {
	rje = min(rje, eval(P(0, (int) Sor.size()-1), P(p[i][0], 
							max(i ? prefmax[i-1] : 0, sufmax[i+1]))));
      }
      //      TRACE(p[i][1] _ sufmin[i+1]);

      if (p[i][1] <= moguci_min && (!i || p[i][1] <= prefmin[i-1])) {
	//	TRACE(i _ p[i][1]);
	int prvi_min = lower_bound(tmp, tmp + n, P(p[i][1], -1)) - tmp;
	//	TRACE(i _ prvi_min _ vrati(1, 0, TOUR, i, prvi_min));
	rje = min(rje, eval(P(0, (int) Sor.size()-1), P(p[i][1],
							max(vrati(1, 0, TOUR, i, prvi_min), max(i ? prefmax[i-1] : 0, sufmax[prvi_min])))));
      }
    }

    // rje = max(0ll, rje);
    // ll br = brute();
    // if (br != rje) {
    //   TRACE(n _ br _ rje);
    //   REP(i, n) TRACE(Sor[p[i][0]] _ Sor[p[i][1]]);
    // }
    // assert(rje == brute());
    printf("%lld\n", rje);  
    break;

  }

  return 0;
}
