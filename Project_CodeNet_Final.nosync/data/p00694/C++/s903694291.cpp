#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory>
#include <cstring>
#include <cassert>
#include <numeric>
#include <sstream>
#include <complex>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cctype>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define REP2(i, m, n) for (int i = (int)(m); i < (int)(n); i++)
#define REP(i, n) REP2(i, 0, n)
#define ALL(S) (S).begin(), (S).end()

template <typename T, typename E>
ostream &operator<<(std::ostream &os, const std::pair<T, E> &p){
  return os << "(" << p.first << ", " << p.second << ")";
}

typedef tuple<int, int, int> Point3D;

Point3D operator-(const Point3D &p1, const Point3D &p2){
  return make_tuple(get<0>(p1) - get<0>(p2),
                    get<1>(p1) - get<1>(p2),
                    get<2>(p1) - get<2>(p2));
}

Point3D operator+(const Point3D &p1, const Point3D &p2){
  return make_tuple(get<0>(p1) + get<0>(p2),
                    get<1>(p1) + get<1>(p2),
                    get<2>(p1) + get<2>(p2));
}

struct Key {
  map<int, Point3D> P;
  map<Point3D, int> I;
  map<int, vector<int> > E; 
  
  void load(int n){
    map<string, Point3D> L;
    string s;
    int x = 0, y = 0, z = 0, nx, ny, nz;
    
    P[0] = make_tuple(0, 0, 0);
    I[make_tuple(0, 0, 0)] = 0;
    
    while (n--){
      cin >> s;
      tie(nx, ny, nz) = make_tuple(x, y, z);
      if (s.back() == 'x'){
        nx = (s[0] == '-' ? x - 1 : x + 1);
      } else if (s.back() == 'y'){
        ny = (s[0] == '-' ? y - 1 : y + 1);
      } else if (s.back() == 'z'){
        nz = (s[0] == '-' ? z - 1 : z + 1);
      } else {
        if (L.count(s) == 0) L[s] = make_tuple(x, y, z);
        else tie(x, y, z) = L[s];
        continue;
      }

      if (I.count(make_tuple(nx, ny, nz)) == 0){
        int id = I.size();
        I[make_tuple(nx, ny, nz)] = id;
        P[id] = make_tuple(nx, ny, nz);
      }

      int u = I[make_tuple(x, y, z)];
      int v = I[make_tuple(nx, ny, nz)];
      E[u].push_back(v);
      E[v].push_back(u);
      tie(x, y, z) = make_tuple(nx, ny, nz);
    }
  }

  void rotate_x(){
    map<Point3D, int> NI;
    for (auto &p : P){
      int x, y, z;
      tie(x, y, z) = p.second;
      p.second = make_tuple(x, -z, y);
      NI[p.second] = p.first;
    }
    I = NI;
  };
  void rotate_y(){
    map<Point3D, int> NI;
    for (auto &p : P){
      int x, y, z;
      tie(x, y, z) = p.second;
      p.second = make_tuple(-z, y, x);
      NI[p.second] = p.first;
    }
    I = NI;
  };
  
  void rotate_z(){
    map<Point3D, int> NI;
    for (auto &p : P){
      int x, y, z;
      tie(x, y, z) = p.second;
      p.second = make_tuple(-y, x, z);
      NI[p.second] = p.first;
    }
    I = NI;
  }
};


bool check(Key key1, Key key2){
  auto P1 = key1.P;
  auto P2 = key2.P;
  if (P1.size() != P2.size()) return false;

  int n = P1.size();
  REP(i, n){
    Point3D d = P2[i] - P1[0];
    
    bool ok = true;
    REP(j, n){
      if (key2.I.count(P1[j] + d) == 0) ok = false;
      if (key1.I.count(P2[j] - d) == 0) ok = false;
    }

    if (ok){
      REP(j, n) if (ok){
        for (int k : key1.E[j]){
          int nj = key2.I[P1[j] + d];
          int nk = key2.I[P1[k] + d];
          if (find(ALL(key2.E[nj]), nk) == key2.E[nj].end()) ok = false;
        }
      }
      REP(j, n) if (ok){
        for (int k : key2.E[j]){
          int nj = key1.I[P2[j] - d];
          int nk = key1.I[P2[k] - d];
          if (find(ALL(key1.E[nj]), nk) == key1.E[nj].end()) ok = false;
        }
      }
    }
    if (ok) return true;
  }
  return false;
}

bool same(Key key1, Key key2){
  REP(z_, 4){
    REP(y_, 4){
      REP(x_, 4){
        if (check(key1, key2)) return true;
        key1.rotate_x();
      }
      key1.rotate_y();
    }
    key1.rotate_z();
  }
  return false;
}
  

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n && n){
    Key key1;
    Key key2;
    key1.load(n);
    cin >> n;
    key2.load(n);
    cout << (same(key1, key2) ? "SAME" : "DIFFERENT") << endl;
  }
  return 0;
}