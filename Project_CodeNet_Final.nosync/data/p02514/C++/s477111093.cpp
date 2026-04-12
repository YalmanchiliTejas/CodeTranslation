#include<iostream>
#include<sstream>
#include<algorithm>
#include<list>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<limits>
#include<numeric>
#include<functional>

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>

#define IN(x,s,g) ((x) >= (s) && (x) < (g))
#define ISIN(x,y,w,h) (IN((x),0,(w)) && IN((y),0,(h)))
#define f first
#define s second
#define mp make_pair

#define print(x) printf("%d\n",x)

#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define rep(i,s,n) for(int i=(s); i<(int)(n); i++)

typedef unsigned int uint;
typedef long long ll;

const int _dx[] = {0,1,0,-1};
const int _dy[] = {-1,0,1,0};

template<class T>
T gcd(T a, T b){
  if(a > b){ T tmp = b; b = a; a = b; }
  if(a == 0) return b;
  return gcd(a, b % a);
}
int getInt(){
  int ret = 0,c;
  c = getchar();
  while(!isdigit(c)) c = getchar();
  while(isdigit(c)){
    ret *= 10;
    ret += c - '0';
    c = getchar();
  }
  return ret;
}

using namespace std;

int u[100];

int get(int i){
  if(i == u[i]) return i;
  return u[i] = get(u[i]);
}

int main(){
  ll n, m;
  while(scanf("%lld%lld", &n, &m), n + m){
    typedef pair<ll, pair<int, int> > data;
    vector<data> v;
    ll ans = 0;

    REP(i, m){
      int a, b;
      ll c;
      scanf("%d%d%lld", &a, &b, &c);

      if(c > 0){
        v.push_back(mp(c, mp(a, b)));
      }else{
        ans += c;
      }
    }

    sort(v.begin(), v.end());

    int tmp = INT_MAX;

    for(int aa = -1; aa < (int)v.size(); aa++){
      for(int bb = aa; bb < (int)v.size(); bb++){
        bool ok = false;

        REP(i, n) u[i] = i;

        REP(i, v.size()) if(i != aa && i != bb){
          int a = v[i].s.f;
          int b = v[i].s.s;

          u[get(a)] = u[get(b)] = min(get(a), get(b));
        }

        REP(i, n - 1){
          if(get(i) != get(i + 1)){
            ok = true;
            break;
          }
        }

        //printf("%d %d: ",aa,bb); REP(i,n) printf("%d=%d",i,get(i)); puts("");

        if(ok){
          int cost = 0;

          if(aa != -1) cost += v[aa].f;
          if(bb != aa) cost += v[bb].f;

          tmp = min(tmp, cost);
        }
      }
    }

    print((int)(ans + tmp));
  }
  return 0;
}