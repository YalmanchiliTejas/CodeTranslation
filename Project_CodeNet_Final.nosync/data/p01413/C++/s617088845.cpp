/*
 * 2296.cc: Quest of Merchant
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>
 
using namespace std;

/* constant */

const int MAX_N = 7;
const int MAX_M = 7;
const int MAX_W = 10000;
const int MAX_T = 10000;

const int MAX_NBITS = 1 << MAX_N;
const int MAX_MBITS = 1 << MAX_M;

const int INF = 1 << 30;

/* typedef */

typedef long long ll;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef map<string,int> msi;

/* global variables */

msi pnames;
int vs[MAX_M], ps[MAX_M], maxps[MAX_M];
int xs[MAX_N], ys[MAX_N], msks[MAX_N];
int prs[MAX_N][MAX_M];
int dp[MAX_W + 1];
ll dp0[MAX_T + 1];

/* subroutines */

inline int hdist(int x0, int y0, int x1, int y1) {
  return abs(x1 - x0) + abs(y1 - y0);
}

/* main */

int main() {
  int n, m, w, t;
  cin >> n >> m >> w >> t;

  for (int i = 0; i < m; i++) {
    string s;
    cin >> s >> vs[i] >> ps[i];
    pnames[s] = i;
  }

  for (int i = 0; i < n; i++) {
    int li;
    cin >> li >> xs[i] >> ys[i];
    for (int j = 0; j < li; j++) {
      string s;
      int bj;
      cin >> s >> bj;
      int sj = pnames[s];
      if (ps[sj] > bj) {
	msks[i] |= (1 << sj);
	prs[i][sj] = ps[sj] - bj;
	//printf("prs[%d][%d] = %d\n", i, sj, prs[i][sj]);
      }
    }
    //printf("msks[%d] = %d\n", i, msks[i]);
  }

  int nbits = 1 << n;
  vpii rtps;

  for (int bits = 1; bits < nbits; bits++) {
    vi cs;
    int msk = 0;
    memset(maxps, 0, sizeof(maxps));
    for (int i = 0, bi = 1; i < n; i++, bi <<= 1)
      if (bits & bi) {
	cs.push_back(i);
	msk |= msks[i];
	for (int j = 0, bj = 1; j < m; j++, bj <<= 1)
	  if (msks[i] & bj && maxps[j] < prs[i][j]) maxps[j] = prs[i][j];
      }
    //for (int j = 0; j < m; j++) printf("maxps[%d] = %d\n", j, maxps[j]);

    vpii vps;
    for (int i = 0, bi = 1; i < m; i++, bi <<= 1)
      if (msk & bi) vps.push_back(pii(vs[i], maxps[i]));
      
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= w; i++)
      for (vpii::iterator vit = vps.begin(); vit != vps.end(); vit++) {
	int &vi = vit->first, &pi = vit->second;
	if (i >= vi) {
	  int d0 = dp[i - vi] + pi;
	  if (dp[i] < d0) dp[i] = d0;
	}
      }
    int rp = dp[w];
    if (rp <= 0) continue;

    int rt = INF;
    int cn = cs.size();
    do {
      int d =
	hdist(0, 0, xs[cs[0]], ys[cs[0]]) +
	hdist(0, 0, xs[cs[cn - 1]], ys[cs[cn - 1]]);
      for (int i = 1; i < cn; i++)
	d += hdist(xs[cs[i - 1]], ys[cs[i - 1]], xs[cs[i]], ys[cs[i]]);
      if (rt > d) rt = d;
    } while (next_permutation(cs.begin(), cs.end()));
    if (rt > t) continue;
    
    //printf("bits=%d: rt = %d, rp = %d\n", bits, rt, rp);

    rtps.push_back(pii(rt, rp));
  }
  
  for (int i = 1; i <= t; i++)
    for (vpii::iterator vit = rtps.begin(); vit != rtps.end(); vit++) {
      int &ti = vit->first, &pi = vit->second;
      if (i >= ti) {
	ll d0 = dp0[i - ti] + pi;
	if (dp0[i] < d0) dp0[i] = d0;
      }
    }

  printf("%lld\n", dp0[t]);
  return 0;
}