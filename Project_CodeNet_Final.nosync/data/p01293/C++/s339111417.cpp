#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#define REP(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;

int charmap[256];

int calc(const string &str, char suit, char suit2){
  int ret = charmap[str[0]];
  if(str[1] == suit) ret += 26;
  else if(str[1] == suit2) ret += 13;
  return ret;
}

int main(){
  charmap['2'] = 0; charmap['3'] = 1; charmap['4'] = 2;
  charmap['5'] = 3; charmap['6'] = 4; charmap['7'] = 5;
  charmap['8'] = 6; charmap['9'] = 7;
  charmap['T'] = 8;
  charmap['J'] = 9;
  charmap['Q'] = 10;
  charmap['K'] = 11;
  charmap['A'] = 12;

  string s;
  while(cin >> s, s != "#"){
    string c[4][13];
    int ans[2] = { 0, 0 };
    REP(i,4) REP(j,13) cin >> c[i][j];
    int oya = 0;
    const char suit = s[0];

    REP(i,13){
      vector<pair<int, int> > v;
      const char suit2 = c[oya][i][1];
      REP(j,4){
        v.push_back(make_pair(calc(c[(oya + j) % 4][i], suit, suit2),
                              (oya + j) % 4));
      }
      sort(v.rbegin(), v.rend());
      oya = v[0].second;
      ans[oya % 2]++;
    }

    if(ans[0] > ans[1]) printf("NS %d\n", ans[0] - 6);
    else printf("EW %d\n", ans[1] - 6);
  }
  return 0;
}