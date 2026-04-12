#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <string>
#include <memory.h>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <cctype>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <fstream>
#include <cmath>
using namespace std;

#define REP2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define REP(i, n) REP2(i, 0, n)
#define ALL(c) (c).begin(), (c).end()
#define ITER(c) __typeof((c).begin())
#define PB(e) push_back(e)
#define FOREACH(i, c) for(ITER(c) i = (c).begin(); i != (c).end(); ++i)
#define MP(a, b) make_pair(a, b)
#define PARITY(n) ((n) & 1)

typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1000 * 1000 * 1000 + 7;
const double EPS = 1e-10;

vector<string> normalize(string s, bool compress){
  REP(i, s.size()) if(s[i] == '/') s[i] = ' ';
  istringstream in(s);
  vector<string> ss;

  {
    string tmp_s;
    while(in >> tmp_s) ss.push_back(tmp_s);
  }

  if(compress){
    int m = 0;
    REP(i, ss.size()){
      if(ss[i] == "."){
        continue;
      }else if(ss[i] == ".."){
        m--;
        assert(m >= 0);
      }else{
        ss[m++] = ss[i];
      }
    }
    ss.resize(m);
  }
  return ss;
}

int get_idx(const vector<vector<string> > &vvs, string s){

  bool is_file = false;
  
  if(*s.rbegin() == '.') s += '/';
  if(*s.rbegin() == '/'){
    is_file = true;
    s += "index.html";
  }
  
  vector<string> vs = normalize(s, false);
      
  int m = 0;

  REP(i, vs.size()){
    if(vs[i] == ".") continue;
    else if(vs[i] == ".."){
      if(--m < 0) return -1;
    }else{
      vs[m++] = vs[i];
      bool ok = false;
      REP(j, vvs.size()){
        if(i < (int)vs.size() - 1 && m >= (int)vvs[j].size()) continue;
        
        size_t l = min(m, (int)vvs[j].size());
        vector<string> tmp_vs1 = vector<string>(vvs[j].begin(), vvs[j].begin() + l);
        vector<string> tmp_vs2 = vector<string>(vs.begin(), vs.begin() + m);
        if(tmp_vs1 == tmp_vs2) ok = true;
      }
      if(!ok) return -1;
    }
  }

  vs.resize(m);
  REP(i, vvs.size()) if(vvs[i] == vs) return i;
  if(!is_file){
    vs.push_back("index.html");
    REP(i, vvs.size()) if(vvs[i] == vs) return i;
  }
  return -1;
}

int main(){
  int N, M;
  while(cin >> N >> M && N + M > 0){
    string s,t;
    vector<vector<string> > vvs;
    REP(i, N){
      cin >> s;
      vvs.push_back(normalize(s, true));
    }
    REP(i, M){
      cin >> s >> t;
      int si = get_idx(vvs, s);
      int ti = get_idx(vvs, t);

      if(si == -1 || ti == -1) {
        cout << "not found" << endl;
      }else{
        cout << (si == ti ? "yes" : "no") << endl;
      }
    }
  }
  return 0;

}