
#include <bits/stdc++.h>
#include <math.h>
#define REP(i, n) for(int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1001001001;
const int mINF = -1001001001;


int main() {
int h,w;
cin >> h >> w;
char a[h][w];
vector<int> h_co,w_co;
int h_count;
int w_count;
REP(i,h) {
  h_count = 0;
  REP(j,w) {
    cin >> a[i][j];
    if(a[i][j]=='.') h_count++;
  }
  if(h_count!=w) h_co.push_back(i);
}
REP(i,w) {
  w_count = 0;
  REP(j,h) {
    if(a[j][i]=='.') w_count++;
  }
  if(w_count!=h) w_co.push_back(i);
}
for(int i:h_co) {
  for(int j:w_co) {
    cout << a[i][j];
  }
  cout << endl;
}
return 0;
}
