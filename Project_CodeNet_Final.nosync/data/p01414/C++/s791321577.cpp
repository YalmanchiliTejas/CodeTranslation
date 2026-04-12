#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <numeric>
#include <bitset>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
#include <cassert>
using namespace std;

typedef long long ll;
static const double EPS = 1e-8;
static const double PI = 4.0 * atan(1.0);
bool ISINT(double x){return fabs(x-(int)x)<EPS;}
bool ISEQ(double x,double y){return fabs(x-y)<EPS;}
string itos(ll x){stringstream ss;ss<<x;return ss.str();}
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define EREP(i,a,b) for(int i=a;i<=b;i++)
#define erep(i,n) EREP(i,0,n)
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin();itr!=c.end();itr++)

typedef pair<int,int> P;

int n;
int h[16],w[16];
int b[16][3][8][8],b2[16][3][8][8];
bool closed[1<<16];
char t[10][10],ch[]="RGB";

void show(int bit){
  rep(i,16){
    if(bit & (1<<i)){
      cout<<1;
    }
    else{
      cout<<0;
    }
  }
  cout<<endl;
}

void solve(){
  queue<P> open;
  memset(closed,0,sizeof(closed));
  open.push(P(0,0));
  closed[0] = true;

  while(!open.empty()){
    P p = open.front(); open.pop();

    if(p.second == (1<<16)-1){
      printf("%d\n",p.first);
      return;
    }

    rep(k,n){
      rep(color,3){
        REP(si,-h[k]+1,4){
          REP(sj,-w[k]+1,4){
            int bit = p.second;
            bit |= b[k][color][si+4][sj+4];
            bit -= (bit & b2[k][color][si+4][sj+4]);

            if(!closed[bit]){
              closed[bit] = true;
              open.push(P(p.first+1,bit));
            }
          }
        }
      }
    }
  }

  printf("-1\n");
}

int main(void){
  while(scanf("%d",&n) != EOF){
    rep(i,n){
      scanf("%d%d",&h[i],&w[i]);
    }

    rep(i,4){
      scanf("%s",t[i]);
    }

    rep(k,n){
      rep(color,3){
        REP(si,-h[k]+1,4){
          REP(sj,-w[k]+1,4){
            int bit = 0;
            int bit2 = 0;

            REP(i,si,si+h[k]){
              REP(j,sj,sj+w[k]){
                if(i < 0 || j < 0 || 4 <= i || 4 <= j) continue;

                int tmpBit = (1<<(i*4+j));
                if(t[i][j] == ch[color]){
                  bit |= tmpBit;
                }
                else{
                  bit2 |= tmpBit;
                }
              }
            }

            b[k][color][si+4][sj+4] = bit;
            b2[k][color][si+4][sj+4] = bit2;
          }
        }
      }
    }

    solve();
  }
}