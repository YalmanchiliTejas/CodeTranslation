#include <bits/stdc++.h>

using namespace std;

#define LOG(...) fprintf(stderr,__VA_ARGS__)
//#define LOG(...)
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort(ALL(c))
#define RSORT(c) sort(RALL(c))
#define SQ(n) (n)*(n)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main() {
  char strong;
  while(cin>>strong,strong!='#'){
    // tuple<int, int, char, int> cards[13][4];
    vector<tuple<int, int ,char ,int>> cards[13];
    REP(i, 4){
      REP(j, 13){
        char n, m;
        cin >> n >> m;
        switch (n) {
          case 'T':
          n = 10;
          break;
          case 'J':
          n = 11;
          break;
          case 'Q':
          n = 12;
          break;
          case 'K':
          n = 13;
          break;
          case 'A':
          n = 14;
          break;
          default:
          n = n - '0';
          break;
        }
        tuple<int, int, char, int> t = make_tuple((m==strong)?2:0, (int)n, (char)m, (int)i);
        cards[j].push_back(t);
      }
    }
    int direction = 3;
    int p[4] = {0};
    REP(j, 13){
      REP(i, 4){
        strong = get<2>(cards[j][direction]);
        if (get<2>(cards[j][i]) == strong) get<0>(cards[j][i]) = 1;
      }
      RSORT(cards[j]);
      direction = get<3>(cards[j][0]);
      p[direction]++;
      // LOG("%d", direction);
    }
    if (p[0] + p[2] > p[1] + p[3]){
      printf("NS %d\n", (p[0]+p[2])%6);
    }else{
      printf("EW %d\n", (p[1]+p[3])%6);
    }
  }
}