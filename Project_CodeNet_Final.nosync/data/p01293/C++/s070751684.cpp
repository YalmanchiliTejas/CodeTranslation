#include <iostream>
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
#define SQ(x) ((x)*(x))
#define Mod(x, mod) (((x)+(mod)%(mod))
#define MP make_pair
#define PB push_back
#define Fi first
#define Se second
#define INF (1<<29)
#define EPS 1e-10
#define MOD 1000000007

typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef vector<int> vi;
typedef queue<int> qi;
typedef long long ll;

struct P{
  int rank; char suit;
};

P card[4][16];
int  point[2];
char trump;
map<char, int>m;

P add_card(string s){ return (P){m[s[0]], s[1]}; }

int solve(int sm, vector<P> v){
  int winner = -1;
  rep(i,4){
    if(trump == v[i].suit && ( winner == -1 || v[winner].rank < v[i].rank)) winner = i;
  }

  if(winner!=-1) return winner;

  rep(i,4){
    if(v[sm].suit == v[i].suit && (winner == -1 || v[winner].rank < v[i].rank)) winner = i;
  }

  return winner;
}

int main(){
  m['A']=14;m['2']=2;m['3']=3;m['4']=4;m['5']=5;m['6']=6;m['7']=7;m['8']=8;m['9']=9;m['T']=10;m['J']=11;m['Q']=12;m['K']=13;
  while(cin >> trump && trump != '#'){
    rep(i,4) rep(j,13){
      string s; cin >> s;
      card[i][j] = add_card(s);
    }
    //    rep(i,4){ rep(j,13) cout << card[i][j].rank << " " << card[i][j].suit << " "; cout << endl; }

    point[0]=point[1]=0;
    int sm=0;// start member
    rep(i,13){
      vector<P>v; rep(j, 4) v.push_back(card[j][i]); 
      int winner = solve(sm, v);
      point[winner%2]++;
      sm = winner;
     }

    if(point[0]>point[1]) cout << "NS " << point[0]-6 << endl;
    else cout << "EW " << point[1]-6 << endl;
  }
  return 0;
}