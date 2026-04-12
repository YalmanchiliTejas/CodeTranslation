//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <queue>

using namespace std;

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

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

int N, bd[1<<16];
int H[16], W[16];
VS orig(4);


int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  REP(i,N) cin >> H[i] >> W[i];
  REP(i,4) cin >> orig[i];

  vector<PII> trans[16];
  REP(i,N){
	for(int y=-H[i]+1;y<4;++y){
	  for(int x=-W[i]+1;x<4;++x){
		for(int k=0;k<3;++k){
		  int tmp1 = 0, tmp2 = (1<<16)-1;
		  char c = "RGB"[k];
		  for(int dy=0;dy<H[i];++dy){
			int ty = y + dy;
			if(ty < 0 || 4 <= ty) continue;
			for(int dx=0;dx<W[i];++dx){
			  int tx = x + dx;
			  if(tx < 0 || 4 <= tx) continue;
			  if(c == orig[ty][tx])
				tmp1 |= (1 << (ty*4+tx));
			  else
				tmp2 &= ~(1 << (ty*4+tx));
			}
		  }
		  trans[i].PB(MP(tmp1,tmp2));
		}
	  }
	}
  }

  
  priority_queue<PII, vector<PII>, greater<PII>> pq;
  fill(bd, bd+(1<<16), 1000);
  bd[0] = 0;
  pq.push(MP(0,0));
  while(!pq.empty()){
	PII pii = pq.top(); pq.pop();
	int ct = pii.first;
	int state = pii.second;
	if(ct > bd[state]) continue;

	REP(i,16){
	  for(PII& pii: trans[i]){
		int tmp = state;
		tmp |= pii.first;
		tmp &= pii.second;
		if(bd[tmp] > ct+1){
		  bd[tmp] = ct + 1;
		  pq.push(MP(bd[tmp], tmp));
		}
	  }
	}
  }
  

  cout << bd[(1<<16)-1] << endl;
  
  return 0;
}