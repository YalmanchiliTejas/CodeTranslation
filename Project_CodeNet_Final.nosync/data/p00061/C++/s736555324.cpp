#include <bits/stdc++.h>
using namespace std;

#define iota(i,n,b,s) for(int i=int(b);i!=int((b)+(s)*(n));i+=(s))
#define range(i,n,m) iota(i,(((n)>(m))?((n)-(m)):((m)-(n))),(n),((n)>(m)?-1:1))
#define rep(i,n) iota(i,(n),0,1)
#define loop for(;;)

#define INF (1e9)
#define EPS (1e-9)
#define cons(a,b) (make_pair(a,b))
#define car(a) (a.first)
#define cdr(a) (a.second)
#define cadr(a) (car(cdr(a)))
#define cddr(a) (cdr(cdr(a)))
#define all(a) a.begin(), a.end()
#define trace(var) cerr<<">>> "<<#var<<" = "<<var<<endl;

typedef long long Integer;
typedef double Real;
typedef vector<int> vi;
typedef vector<string> vs;
typedef map<string,int> Dictionary;
const Real PI = acos(-1);

template<class S, class T>
ostream& operator<<(ostream& os, pair<S,T> p) {
  os << '(' << car(p) << ", " << cdr(p) << ')';
  return os;
}

template<class T>
ostream& operator<<(ostream& os, vector<T> v) {
  if (v.size() == 0) {
    os << "(empty)";
    return os;
  }
  os << v[0];
  for (int i=1, len=v.size(); i<len; ++i) os << ' ' << v[i];
  return os;
}

int dx[] = { -1, 0, 1, 0 };
int dy[] = {  0, -1, 0, 1 };

vector<int>f(int n){
  vector<int>r;
  for(;n;n/=10)r.push_back(n%10);
  sort(all(r));
  return r;
}

int g(vector<int>r){
  int n=0;
  for(int x:r)n=n*10+x;
  return n;
}

int main() {

  vector<pair<int,int>> ps;
  int id_max = 0;
  loop {
    int id, x;
    char com;
    cin >> id >> com >> x;
    if (!id&&!x)break;
    id_max = max(id_max, id);
    ps.push_back(cons(-x,id));
  }
  sort(all(ps));

  int ji[id_max + 1];
  int k = 1;
  int last = car(ps[0]);
  rep (i, ps.size()) {
    if (last != car(ps[i])) {
      ++k;
      last = car(ps[i]);
    }
    ji[cdr(ps[i])] = k;
  }

  loop {
    int n; cin >> n;
    if (!cin) break;
    cout << ji[n] << endl;
  }

  return 0;
}