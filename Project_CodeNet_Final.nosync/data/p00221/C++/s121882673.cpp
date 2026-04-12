#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

#define rep(i,j) REP((i), 0, (j))
#define REP(i,j,k) for(int i=(j);(i)<(k);++i)
#define BW(a,x,b) ((a)<=(x)&&(x)<=(b))
#define ALL(v) (v).begin(), (v).end()
#define LENGTHOF(x) (sizeof(x) / sizeof(*(x)))
#define AFILL(a, b) fill((int*)a, (int*)(a + LENGTHOF(a)), b)
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define INF 1 << 30
#define EPS 1e-10

typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef vector<int> vi;
typedef queue<int> qi;
typedef long long ll;

int M, N;

int judge(string in, int n){
  string s;
  if(n % 5 == 0 && n % 3 == 0) return in == "FizzBuzz";
  if(n % 5 == 0) return in == "Buzz";
  if(n % 3 == 0) return in == "Fizz";
  if(!isdigit(in[0])) return false;
  return n == atoi(in.c_str());
}

int main(){
  while(scanf("%d%d", &M, &N) && M+N){
    vector<int>p(M);
    rep(i, M) p[i] = i+1;

    int pos = 0, w = -1;
    REP(i, 1, N+1){
      string s;
      cin >> s;
      if(w != -1) continue;
      if(!judge(s, i)){
	p.erase(p.begin()+pos);
      }else{
	pos++;
      }
      pos = pos%p.size();
      if(p.size() == 1) w = p[0];
    }
    rep(i, p.size()) printf(i?" %d":"%d", p[i]); puts("");
  }
  return 0;
}