#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
#define rrep(i, m, n) for(int (i)=(m); (i)<(n);  (i)++)
#define erep(i, m, n) for(int (i)=(m); (i)<=(n); (i)++)
#define  rep(i, n)    for(int (i)=0; (i)<(n);  (i)++)
#define rrev(i, m, n) for(int (i)=(n)-1; (i)>=(m); (i)--)
#define erev(i, m, n) for(int (i)=(n); (i)>=(m); (i)--)
#define  rev(i, n)    for(int (i)=(n)-1; (i)>=0; (i)--)
#define vrep(i, c)    for(__typeof((c).begin())i=(c).begin(); i!=(c).end(); i++)
#define  ALL(v)       (v).begin(), (v).end()
#define mp            make_pair
#define pb            push_back
template<class T, class S> inline bool minup(T& m, S x){ return m>(T)x ? (m=(T)x, true) : false; }
template<class T, class S> inline bool maxup(T& m, S x){ return m<(T)x ? (m=(T)x, true) : false; }

const int    INF = 1000000000;
const ll     MOD = 1000000007LL;
const double EPS = 1E-12;

template<typename T> ostream& operator <<(ostream& r, const vector<T> t){vrep(v,t)r<<*v<<(v+1==t.end()?"":" ");return r;}
template<typename T> ostream& operator <<(ostream& r, const pair<vector<T>, int> p){int n=p.second;minup(n,p.first.size());rep(i,n-1)r<<p.first[i]<<' ';r<<p.first[n-1];return r;}
template<typename T> ostream& operator <<(ostream& r, const pair<T*, int> p){int n=p.second-1;rep(i,n)r<<p.first[i]<<' ';return r<<p.first[n];}
template<typename T, size_t S> ostream& operator <<(ostream& r, const T (&a)[S]){rep(i,S-1)r<<a[i]<<' ';return r<<a[S-1];}


const int MAX_N = 15;
int a[MAX_N][MAX_N];
int n;

inline int nextX(int& x){ return x = (x + n - 1) % n; }
inline int nextY(int& y){ return y = (y + 1) % n; }
inline int prevY(int& y){ return y = (y + n - 1) % n; }

int main()
{
  while((cin >> n) && n){
    rep(i, n) rep(j, n) a[i][j] = 0;
    int hx = n / 2;
    int hy = n / 2 - 1;
    erep(cnt, 1, n * n){
      if(!a[nextX(hx)][nextY(hy)]) a[hx][hy] = cnt;
      else a[nextX(hx)][prevY(hy)] = cnt;
    }
    rev(i, n) rep(j, n) printf("%4d%s", a[i][j], (j >= n - 1 ? "\n" : ""));
 }

  return 0;
}