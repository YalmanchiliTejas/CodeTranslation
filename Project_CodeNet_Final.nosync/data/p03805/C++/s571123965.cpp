#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);i++)
#define ALL(a)  (a).begin(),(a).end()
#define SORT(c) sort((c).begin(),(c).end())
#define REV(c) reverse((c).begin(),(c).end())

using namespace std;
typedef pair<int,int> P;

// 最大公約数
int64_t gcd(int64_t a, int64_t b) {
  return b != 0 ? gcd(b, a % b) : a;
}

// 最小公倍数
int64_t lcm(int64_t a, int64_t b) {
  return a * b / gcd(a, b);
}

int ctoi(char c){
  return c - '0';
}


int n,m;
vector<P> vec(10000);
int rec(int x, auto reached){
  int t=0;
  reached[x] = true;
  bool r2[10];
  REP(i,n+1){
    r2[i] = reached[i];
  }
  bool chk=true;
  REP(i,n+1){
    if (i!=0){
      if (!r2[i]){
        chk = false;
      }
    }
  }
  if (chk){return 1;}
  REP(i,m){
    bool r[10];
    REP(i,n+1){
      r[i] = reached[i];
    }
    int f = vec.at(i).first;
    int s = vec.at(i).second;
    if (vec.at(i).first == x){
      if (!r[vec.at(i).second]){
        t += rec(vec.at(i).second, r);
      }
    } else if (vec.at(i).second == x){
      if (!r[vec.at(i).first]){
        t += rec(vec.at(i).first, r);
      }
    }
  }
  return t;
}

int main(){
  cin >> n >> m;
  bool reached[10];
  REP(i,10){
    reached[i] = false;
  }
  REP(i,m){
    cin >> vec.at(i).first >> vec.at(i).second;
  }
  int t = rec(1,reached);
  cout << t << endl;
  return 0;
}


